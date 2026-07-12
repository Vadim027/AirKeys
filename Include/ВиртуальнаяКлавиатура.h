#pragma once
//
// Файл: ВиртуальнаяКлавиатура.h
// Назначение: панель с клавишами и обработка KeyPress
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
    //
    void setCapsLockState(bool _isCapsLockOn);
    bool isCapsLockOn(void) const { return FCapsLockOn; }
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
        enterKey
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
    KeyPress makeKeyPressForSpec(const TKeySpec& _keySpec) const;
    String makeLabelForSpec(const TKeySpec& _keySpec) const;
    void handleKeyButtonClick(TVirtualKeyButton* _button);
    //
    bool FCapsLockOn;
    int FKeyGap;
    int FRowGap;
    OwnedArray<TVirtualKeyButton> FKeyButtons;
    static const TKeySpec FKeyboardLayout[];
    static const int FKeyboardLayoutSize;
    //
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TVirtualKeyboard)
};
