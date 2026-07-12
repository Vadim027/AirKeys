#include "../Include/ВиртуальнаяКлавиатура.h"
//
// Раскладка клавиатуры: текст на кнопке, заглавный вариант (для букв), тип клавиши, ширина
const TVirtualKeyboard::TKeySpec TVirtualKeyboard::FKeyboardLayout[] =
{
    { L"1", nullptr, TKeyKind::characterKey, 1 },
    { L"2", nullptr, TKeyKind::characterKey, 1 },
    { L"3", nullptr, TKeyKind::characterKey, 1 },
    { L"4", nullptr, TKeyKind::characterKey, 1 },
    { L"5", nullptr, TKeyKind::characterKey, 1 },
    { L"6", nullptr, TKeyKind::characterKey, 1 },
    { L"7", nullptr, TKeyKind::characterKey, 1 },
    { L"8", nullptr, TKeyKind::characterKey, 1 },
    { L"9", nullptr, TKeyKind::characterKey, 1 },
    { L"Backspace", nullptr, TKeyKind::backspaceKey, 1 },
    //
    { L"а", L"А", TKeyKind::characterKey, 1 },
    { L"б", L"Б", TKeyKind::characterKey, 1 },
    { L"в", L"В", TKeyKind::characterKey, 1 },
    { L"г", L"Г", TKeyKind::characterKey, 1 },
    { L"д", L"Д", TKeyKind::characterKey, 1 },
    { L"е", L"Е", TKeyKind::characterKey, 1 },
    { L"ё", L"Ё", TKeyKind::characterKey, 1 },
    { L"ж", L"Ж", TKeyKind::characterKey, 1 },
    { L"з", L"З", TKeyKind::characterKey, 1 },
    { L"и", L"И", TKeyKind::characterKey, 1 },
    { L"й", L"Й", TKeyKind::characterKey, 1 },
    //
    { L"к", L"К", TKeyKind::characterKey, 1 },
    { L"л", L"Л", TKeyKind::characterKey, 1 },
    { L"м", L"М", TKeyKind::characterKey, 1 },
    { L"н", L"Н", TKeyKind::characterKey, 1 },
    { L"о", L"О", TKeyKind::characterKey, 1 },
    { L"п", L"П", TKeyKind::characterKey, 1 },
    { L"р", L"Р", TKeyKind::characterKey, 1 },
    { L"с", L"С", TKeyKind::characterKey, 1 },
    { L"т", L"Т", TKeyKind::characterKey, 1 },
    { L"у", L"У", TKeyKind::characterKey, 1 },
    //
    { L"ф", L"Ф", TKeyKind::characterKey, 1 },
    { L"х", L"Х", TKeyKind::characterKey, 1 },
    { L"ц", L"Ц", TKeyKind::characterKey, 1 },
    { L"ч", L"Ч", TKeyKind::characterKey, 1 },
    { L"ш", L"Ш", TKeyKind::characterKey, 1 },
    { L"щ", L"Щ", TKeyKind::characterKey, 1 },
    { L"ъ", L"Ъ", TKeyKind::characterKey, 1 },
    { L"ы", L"Ы", TKeyKind::characterKey, 1 },
    { L"ь", L"Ь", TKeyKind::characterKey, 1 },
    //
    { L"э", L"Э", TKeyKind::characterKey, 1 },
    { L"ю", L"Ю", TKeyKind::characterKey, 1 },
    { L"я", L"Я", TKeyKind::characterKey, 1 },
    { L"-", nullptr, TKeyKind::characterKey, 1 },
    { L"+", nullptr, TKeyKind::characterKey, 1 },
    { L".", nullptr, TKeyKind::characterKey, 1 },
    { L",", nullptr, TKeyKind::characterKey, 1 },
    { L"!", nullptr, TKeyKind::characterKey, 1 },
    { L"?", nullptr, TKeyKind::characterKey, 1 },
    //
    { L"CapsLock", nullptr, TKeyKind::capsLockKey, 1 },
    { L"Space", nullptr, TKeyKind::spaceKey, 3 },
    { L"Enter", nullptr, TKeyKind::enterKey, 1 }
};
//
const int TVirtualKeyboard::FKeyboardLayoutSize = static_cast<int>(sizeof(FKeyboardLayout) / sizeof(FKeyboardLayout[0]));
//
static const int FRowStarts[] = { 0, 10, 21, 31, 40, 49, 52 };
static const int FRowCount = 6;
//
TVirtualKeyboard::TVirtualKeyButton::TVirtualKeyButton(const String& _buttonText,
                                                       const KeyPress& _keyPress,
                                                       TKeyKind _kind)
    : TextButton(_buttonText),
      FKind(_kind),
      FKeyPress(_keyPress),
      FIsCapsLockActive(false)
{
    if (_keyPress.isValid())
        addShortcut(_keyPress);
}
//
void TVirtualKeyboard::TVirtualKeyButton::updateCapsLockVisual(bool _isCapsLockOn)
{
    if (FKind == TKeyKind::capsLockKey)
    {
        FIsCapsLockActive = _isCapsLockOn;
        setToggleState(_isCapsLockOn, dontSendNotification);
        repaint();
    }
}
//
TVirtualKeyboard::TVirtualKeyboard(void)
    : FCapsLockOn(false),
      FKeyGap(6),
      FRowGap(8)
{
    createKeys();
}
//
void TVirtualKeyboard::createKeys(void)
{
    for (int index = 0; index < FKeyboardLayoutSize; ++index)
    {
        const TKeySpec& keySpec = FKeyboardLayout[index];
        const String buttonLabel = makeLabelForSpec(keySpec);
        const KeyPress keyPress = makeKeyPressForSpec(keySpec);
        //
        auto* keyButton = new TVirtualKeyButton(buttonLabel, keyPress, keySpec.FKind);
        keyButton->onClick = [this, keyButton]() { handleKeyButtonClick(keyButton); };
        //
        if (keySpec.FKind == TKeyKind::capsLockKey)
            keyButton->setClickingTogglesState(false);
        //
        addAndMakeVisible(keyButton);
        FKeyButtons.add(keyButton);
    }
}
//
KeyPress TVirtualKeyboard::makeKeyPressForSpec(const TKeySpec& _keySpec) const
{
    switch (_keySpec.FKind)
    {
        case TKeyKind::backspaceKey:
            return KeyPress(KeyPress::backspaceKey, ModifierKeys(), 0);
        //
        case TKeyKind::enterKey:
            return KeyPress(KeyPress::returnKey, ModifierKeys(), juce_wchar('\n'));
        //
        case TKeyKind::spaceKey:
            return KeyPress(KeyPress::spaceKey, ModifierKeys(), juce_wchar(' '));
        //
        case TKeyKind::capsLockKey:
            return KeyPress();
        //
        case TKeyKind::characterKey:
        default:
        {
            const wchar_t* text = (FCapsLockOn && _keySpec.FTextUpper != nullptr)
                ? _keySpec.FTextUpper
                : _keySpec.FText;
            const juce_wchar character = text[0];
            const int keyCode = static_cast<int>(character);
            return KeyPress(keyCode, ModifierKeys(), character);
        }
    }
}
//
String TVirtualKeyboard::makeLabelForSpec(const TKeySpec& _keySpec) const
{
    if (FCapsLockOn && _keySpec.FTextUpper != nullptr)
        return makeJuceString(_keySpec.FTextUpper);
    //
    return makeJuceString(_keySpec.FText);
}
//
void TVirtualKeyboard::setCapsLockState(bool _isCapsLockOn)
{
    FCapsLockOn = _isCapsLockOn;
    //
    for (int index = 0; index < FKeyButtons.size(); ++index)
    {
        auto* keyButton = FKeyButtons[index];
        const TKeySpec& keySpec = FKeyboardLayout[index];
        //
        keyButton->setButtonText(makeLabelForSpec(keySpec));
        keyButton->FKeyPress = makeKeyPressForSpec(keySpec);
        keyButton->clearShortcuts();
        //
        if (keyButton->FKeyPress.isValid())
            keyButton->addShortcut(keyButton->FKeyPress);
        //
        keyButton->updateCapsLockVisual(FCapsLockOn);
    }
}
//
void TVirtualKeyboard::handleKeyButtonClick(TVirtualKeyButton* _button)
{
    if (_button == nullptr)
        return;
    //
    if (_button->FKind == TKeyKind::capsLockKey)
    {
        FCapsLockOn = !FCapsLockOn;
        setCapsLockState(FCapsLockOn);
        //
        if (FOnCapsLockToggle != nullptr)
            FOnCapsLockToggle();
        //
        return;
    }
    //
    if (FOnKeyPress != nullptr)
        FOnKeyPress(_button->FKeyPress);
}
//
void TVirtualKeyboard::paint(Graphics& g)
{
    g.fillAll(findColour(ResizableWindow::backgroundColourId));
}
//
void TVirtualKeyboard::resized(void)
{
    layoutKeys();
}
//
void TVirtualKeyboard::layoutKeys(void)
{
    const int areaWidth = getWidth();
    const int areaHeight = getHeight();
    const int rowHeight = (areaHeight - (FRowCount - 1) * FRowGap) / FRowCount;
    int currentY = 0;
    //
    for (int rowIndex = 0; rowIndex < FRowCount; ++rowIndex)
    {
        const int rowStart = FRowStarts[rowIndex];
        const int rowEnd = FRowStarts[rowIndex + 1];
        int totalUnits = 0;
        //
        for (int keyIndex = rowStart; keyIndex < rowEnd; ++keyIndex)
            totalUnits += FKeyboardLayout[keyIndex].FWidthUnits;
        //
        const int totalGapWidth = (rowEnd - rowStart - 1) * FKeyGap;
        int totalInternalGapWidth = 0;
        //
        for (int keyIndex = rowStart; keyIndex < rowEnd; ++keyIndex)
            totalInternalGapWidth += FKeyGap * (FKeyboardLayout[keyIndex].FWidthUnits - 1);
        //
        const int unitWidth = (areaWidth - totalGapWidth - totalInternalGapWidth) / jmax(1, totalUnits);
        int currentX = 0;
        //
        for (int keyIndex = rowStart; keyIndex < rowEnd; ++keyIndex)
        {
            const int keyWidth = unitWidth * FKeyboardLayout[keyIndex].FWidthUnits
                               + FKeyGap * (FKeyboardLayout[keyIndex].FWidthUnits - 1);
            //
            if (auto* keyButton = FKeyButtons[keyIndex])
                keyButton->setBounds(currentX, currentY, keyWidth, rowHeight);
            //
            currentX += keyWidth + FKeyGap;
        }
        //
        currentY += rowHeight + FRowGap;
    }
}
