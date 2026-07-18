#pragma once
//
// Файл: ВиртуальнаяКлавиатура.h
// Назначение: панель с клавишами, обработка KeyPress, переключение раскладки RU/EN
//
#include "../JuceLibraryCode/JuceHeader.h"
#include "ВспомогательныеСтроки.h"
//
class TVirtualKeyboard : public Component
{
public:
    TVirtualKeyboard(void);
    //
    std::function<void(const KeyPress&)> FOnKeyPress;
    std::function<void(void)> FOnCapsLockToggle;
    std::function<void(void)> FOnLayoutChange;                  // НОВОЕ: уведомление о смене раскладки
    //
    void setCapsLockState(bool _isCapsLockOn);
    bool isCapsLockOn(void) const { return FCapsLockOn; }
    bool isEnglishLayout(void) const;                            //
    //
    void paint(Graphics& g) override;
    void resized(void) override;
    //
private:
    enum class TKeyKind
    {
        characterKey,
        backspaceKey,
        capsLockKey,
        spaceKey,
        enterKey,
        layoutSwitchKey                                          // добавил клавишу переключения раскладки
    };
    //
    enum class TLayoutKind                                       // показал доступные раскладки клавиатуры
    {
        russian,
        english
    };
    //
    struct TKeySpec
    {
        const wchar_t* FText;
        const wchar_t* FTextUpper;
        TKeyKind FKind;
        int FWidthUnits;
    };
    //
    class TVirtualKeyButton : public TextButton
    {
    public:
        TVirtualKeyButton(const String& _buttonText, const KeyPress& _keyPress, TKeyKind _kind);
        //
        TKeyKind FKind;
        KeyPress FKeyPress;
        bool FIsCapsLockActive;
        //
        void updateCapsLockVisual(bool _isCapsLockOn);
    };
    //
    void createKeys(void);
    void layoutKeys(void);
    void switchLayout(void);                                     // обработка нажатия клавиши смены раскладки
    KeyPress makeKeyPressForSpec(const TKeySpec& _keySpec) const;
    String makeLabelForSpec(const TKeySpec& _keySpec) const;
    void handleKeyButtonClick(TVirtualKeyButton* _button);
    //
    // вспомогательные методы доступа к данным текущей активной раскладки
    const TKeySpec* getActiveLayoutData(void) const;
    int getActiveLayoutSize(void) const;
    const int* getActiveRowStarts(void) const;
    int getActiveRowCount(void) const;
    //
    bool FCapsLockOn;
    TLayoutKind FCurrentLayout;                                  // текущая активная раскладка
    int FKeyGap;
    int FRowGap;
    OwnedArray<TVirtualKeyButton> FKeyButtons;
    //
    static const TKeySpec FKeyboardLayoutRussian[];              // ПЕРЕИМЕНОВАЛ из FKeyboardLayout
    static const int FKeyboardLayoutRussianSize;
    static const int FRowStartsRussian[];
    static const int FRowCountRussian;
    //
    static const TKeySpec FKeyboardLayoutEnglish[];               // английская раскладка
    static const int FKeyboardLayoutEnglishSize;
    static const int FRowStartsEnglish[];
    static const int FRowCountEnglish;
    //
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TVirtualKeyboard)
};