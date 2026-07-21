#include "../Include/ВиртуальнаяКлавиатура.h"
//
// Раскладка клавиатуры (русская): текст на кнопке, заглавный вариант (для букв), тип клавиши, ширина
const TVirtualKeyboard::TKeySpec TVirtualKeyboard::FKeyboardLayoutRussian[] =
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
    { L"0", nullptr, TKeyKind::characterKey, 1 },
    { L"Space", nullptr, TKeyKind::spaceKey, 2 },
    { L"Enter", nullptr, TKeyKind::enterKey, 1 },
    { L"Lang", nullptr, TKeyKind::layoutSwitchKey, 1 }
};
//
const int TVirtualKeyboard::FKeyboardLayoutRussianSize =
static_cast<int>(sizeof(FKeyboardLayoutRussian) / sizeof(FKeyboardLayoutRussian[0]));
//
const int TVirtualKeyboard::FRowStartsRussian[] = { 0, 10, 21, 31, 40, 49, 54 };
const int TVirtualKeyboard::FRowCountRussian = 6;
//
// Раскладка клавиатуры (английская): те же цифры и служебные клавиши, латинские буквы вместо кириллицы
const TVirtualKeyboard::TKeySpec TVirtualKeyboard::FKeyboardLayoutEnglish[] =
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
    { L"q", L"Q", TKeyKind::characterKey, 1 },
    { L"w", L"W", TKeyKind::characterKey, 1 },
    { L"e", L"E", TKeyKind::characterKey, 1 },
    { L"r", L"R", TKeyKind::characterKey, 1 },
    { L"t", L"T", TKeyKind::characterKey, 1 },
    { L"y", L"Y", TKeyKind::characterKey, 1 },
    { L"u", L"U", TKeyKind::characterKey, 1 },
    { L"i", L"I", TKeyKind::characterKey, 1 },
    { L"o", L"O", TKeyKind::characterKey, 1 },
    { L"p", L"P", TKeyKind::characterKey, 1 },
    //
    { L"a", L"A", TKeyKind::characterKey, 1 },
    { L"s", L"S", TKeyKind::characterKey, 1 },
    { L"d", L"D", TKeyKind::characterKey, 1 },
    { L"f", L"F", TKeyKind::characterKey, 1 },
    { L"g", L"G", TKeyKind::characterKey, 1 },
    { L"h", L"H", TKeyKind::characterKey, 1 },
    { L"j", L"J", TKeyKind::characterKey, 1 },
    { L"k", L"K", TKeyKind::characterKey, 1 },
    { L"l", L"L", TKeyKind::characterKey, 1 },
    //
    { L"z", L"Z", TKeyKind::characterKey, 1 },
    { L"x", L"X", TKeyKind::characterKey, 1 },
    { L"c", L"C", TKeyKind::characterKey, 1 },
    { L"v", L"V", TKeyKind::characterKey, 1 },
    { L"b", L"B", TKeyKind::characterKey, 1 },
    { L"n", L"N", TKeyKind::characterKey, 1 },
    { L"m", L"M", TKeyKind::characterKey, 1 },
    { L"-", nullptr, TKeyKind::characterKey, 1 },
    { L"+", nullptr, TKeyKind::characterKey, 1 },
    { L".", nullptr, TKeyKind::characterKey, 1 },
    //
    { L",", nullptr, TKeyKind::characterKey, 1 },
    { L"!", nullptr, TKeyKind::characterKey, 1 },
    { L"?", nullptr, TKeyKind::characterKey, 1 },
    //
    { L"CapsLock", nullptr, TKeyKind::capsLockKey, 1 },
    { L"0", nullptr, TKeyKind::characterKey, 1 },
    { L"Space", nullptr, TKeyKind::spaceKey, 2 },
    { L"Enter", nullptr, TKeyKind::enterKey, 1 },
    { L"Lang", nullptr, TKeyKind::layoutSwitchKey, 1 }
};
//
const int TVirtualKeyboard::FKeyboardLayoutEnglishSize =
static_cast<int>(sizeof(FKeyboardLayoutEnglish) / sizeof(FKeyboardLayoutEnglish[0]));
//
const int TVirtualKeyboard::FRowStartsEnglish[] = { 0, 10, 20, 29, 39, 42, 47 };
const int TVirtualKeyboard::FRowCountEnglish = 6;
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
TVirtualKeyboard::TLayoutSwitchButton::TLayoutSwitchButton(TVirtualKeyboard& _owner, const String& _buttonText)
    : TVirtualKeyButton(_buttonText, KeyPress(), TKeyKind::layoutSwitchKey),
      FKeyboardOwner(_owner),
      FLongPressHandled(false)
{
    setClickingTogglesState(false);
}
//
void TVirtualKeyboard::TLayoutSwitchButton::mouseDown(const MouseEvent& _event)
{
    TextButton::mouseDown(_event);
    FLongPressHandled = false;
    startTimer(FLongPressDelayMs);
}
//
void TVirtualKeyboard::TLayoutSwitchButton::mouseUp(const MouseEvent& _event)
{
    TextButton::mouseUp(_event);
    stopTimer();
    //
    if (!FLongPressHandled)
        setToggleState(false, dontSendNotification);
}
//
void TVirtualKeyboard::TLayoutSwitchButton::timerCallback(void)
{
    stopTimer();
    FLongPressHandled = true;
    setToggleState(true, dontSendNotification);
    repaint();
    FKeyboardOwner.showLayoutSelectionMenu(this);
}
//
void TVirtualKeyboard::updateAllToggleVisuals(void)
{
    for (int index = 0; index < FKeyButtons.size(); ++index)
    {
        auto* keyButton = FKeyButtons[index];
        //
        if (keyButton->FKind == TKeyKind::capsLockKey)
            keyButton->updateCapsLockVisual(FCapsLockOn);
        else if (keyButton->FKind == TKeyKind::layoutSwitchKey)
            keyButton->setToggleState(false, dontSendNotification);
    }
}
//
TVirtualKeyboard::TVirtualKeyboard(void)
    : FCapsLockOn(false),
    FCurrentLayout(TLayoutKind::russian),
    FKeyGap(6),
    FRowGap(8)
{
    createKeys();
}
//
bool TVirtualKeyboard::isEnglishLayout(void) const
{
    return FCurrentLayout == TLayoutKind::english;
}
//
const TVirtualKeyboard::TKeySpec* TVirtualKeyboard::getActiveLayoutData(void) const
{
    return (FCurrentLayout == TLayoutKind::russian) ? FKeyboardLayoutRussian : FKeyboardLayoutEnglish;
}
//
int TVirtualKeyboard::getActiveLayoutSize(void) const
{
    return (FCurrentLayout == TLayoutKind::russian) ? FKeyboardLayoutRussianSize : FKeyboardLayoutEnglishSize;
}
//
const int* TVirtualKeyboard::getActiveRowStarts(void) const
{
    return (FCurrentLayout == TLayoutKind::russian) ? FRowStartsRussian : FRowStartsEnglish;
}
//
int TVirtualKeyboard::getActiveRowCount(void) const
{
    return (FCurrentLayout == TLayoutKind::russian) ? FRowCountRussian : FRowCountEnglish;
}
//
void TVirtualKeyboard::createKeys(void)
{
    FKeyButtons.clear(); // при повторном вызове (смена раскладки) сначала удаляем старые кнопки
    //
    const TKeySpec* layoutData = getActiveLayoutData();
    const int layoutSize = getActiveLayoutSize();
    //
    for (int index = 0; index < layoutSize; ++index)
    {
        const TKeySpec& keySpec = layoutData[index];
        const String buttonLabel = makeLabelForSpec(keySpec);
        const KeyPress keyPress = makeKeyPressForSpec(keySpec);
        //
        auto* keyButton = (keySpec.FKind == TKeyKind::layoutSwitchKey)
            ? static_cast<TVirtualKeyButton*>(new TLayoutSwitchButton(*this, makeLabelForSpec(keySpec)))
            : new TVirtualKeyButton(buttonLabel, keyPress, keySpec.FKind);
        //
        if (keySpec.FKind != TKeyKind::layoutSwitchKey)
            keyButton->onClick = [this, keyButton]() { handleKeyButtonClick(keyButton); };
        //
        if (keySpec.FKind == TKeyKind::capsLockKey)
            keyButton->setClickingTogglesState(false);
        //
        addAndMakeVisible(keyButton);
        FKeyButtons.add(keyButton);
    }
    //
    updateAllToggleVisuals();
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
    case TKeyKind::layoutSwitchKey:                            // НОВОЕ: у служебной клавиши нет физического аналога
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
    const TKeySpec* layoutData = getActiveLayoutData();
    //
    for (int index = 0; index < FKeyButtons.size(); ++index)
    {
        auto* keyButton = FKeyButtons[index];
        const TKeySpec& keySpec = layoutData[index];
        //
        keyButton->setButtonText(makeLabelForSpec(keySpec));
        keyButton->FKeyPress = makeKeyPressForSpec(keySpec);
        keyButton->clearShortcuts();
        //
        if (keyButton->FKeyPress.isValid())
            keyButton->addShortcut(keyButton->FKeyPress);
    }
    //
    updateAllToggleVisuals();
}
//
void TVirtualKeyboard::setLayout(TLayoutKind _layout)
{
    if (FCurrentLayout == _layout)
        return;
    //
    FCurrentLayout = _layout;
    FCapsLockOn = false;
    //
    createKeys();
    layoutKeys();
    //
    if (FOnLayoutChange != nullptr)
        FOnLayoutChange();
}
//
void TVirtualKeyboard::showLayoutSelectionMenu(Component* _targetComponent)
{
    PopupMenu layoutMenu;
    //
    layoutMenu.addItem(1, strLayoutRussian(), true, FCurrentLayout == TLayoutKind::russian);
    layoutMenu.addItem(2, strLayoutEnglish(), true, FCurrentLayout == TLayoutKind::english);
    //
    Component::SafePointer<Component> safeTarget(_targetComponent);
    //
    layoutMenu.showMenuAsync(PopupMenu::Options().withTargetComponent(_targetComponent),
        [this, safeTarget](int _result)
        {
            if (safeTarget != nullptr)
            {
                if (auto* layoutButton = dynamic_cast<TLayoutSwitchButton*>(safeTarget.getComponent()))
                {
                    layoutButton->setToggleState(false, dontSendNotification);
                    layoutButton->repaint();
                }
            }
            //
            if (_result == 1)
                setLayout(TLayoutKind::russian);
            else if (_result == 2)
                setLayout(TLayoutKind::english);
        });
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
    //
    const int* rowStarts = getActiveRowStarts();
    const int rowCount = getActiveRowCount();
    const TKeySpec* layoutData = getActiveLayoutData();
    //
    const int rowHeight = (areaHeight - (rowCount - 1) * FRowGap) / rowCount;
    int currentY = 0;
    //
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        const int rowStart = rowStarts[rowIndex];
        const int rowEnd = rowStarts[rowIndex + 1];
        int totalUnits = 0;
        //
        for (int keyIndex = rowStart; keyIndex < rowEnd; ++keyIndex)
            totalUnits += layoutData[keyIndex].FWidthUnits;
        //
        const int totalGapWidth = (rowEnd - rowStart - 1) * FKeyGap;
        int totalInternalGapWidth = 0;
        //
        for (int keyIndex = rowStart; keyIndex < rowEnd; ++keyIndex)
            totalInternalGapWidth += FKeyGap * (layoutData[keyIndex].FWidthUnits - 1);
        //
        const int unitWidth = (areaWidth - totalGapWidth - totalInternalGapWidth) / jmax(1, totalUnits);
        int currentX = 0;
        //
        for (int keyIndex = rowStart; keyIndex < rowEnd; ++keyIndex)
        {
            const int keyWidth = unitWidth * layoutData[keyIndex].FWidthUnits
                + FKeyGap * (layoutData[keyIndex].FWidthUnits - 1);
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