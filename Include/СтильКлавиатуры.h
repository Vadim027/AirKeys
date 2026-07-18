#pragma once
//
// Файл: СтильКлавиатуры.h
// Назначение: пользовательский внешний вид кнопок, редактора и фона
//
#include "../JuceLibraryCode/JuceHeader.h"
//
class TKeyboardLookAndFeel : public LookAndFeel_V4
{
public:
    TKeyboardLookAndFeel(void);
    //
    void drawButtonBackground(Graphics& g,
                              Button& _button,
                              const Colour& _backgroundColour,
                              bool _isMouseOverButton,
                              bool _isButtonDown) override;
    //
    Font getTextButtonFont(TextButton& _button, int _buttonHeight) override;
    //
    void drawButtonText(Graphics& g,
                        TextButton& _button,
                        bool _shouldDrawButtonAsHighlighted,
                        bool _shouldDrawButtonAsDown) override;
    //
    void fillTextEditorBackground(Graphics& g, int _width, int _height, TextEditor& _editor) override;
    //
    void drawTextEditorOutline(Graphics& g, int _width, int _height, TextEditor& _editor) override;
    //
private:
    Colour FAppBackground;
    Colour FEditorBackground;
    Colour FKeyBackground;
    Colour FKeyHoverBackground;
    Colour FKeyActiveBackground;
    Colour FKeyBorder;
    Colour FPrimaryText;
    Colour FAccent;
};
