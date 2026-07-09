#include "../Include/СтильКлавиатуры.h"
//
TKeyboardLookAndFeel::TKeyboardLookAndFeel(void)
{
    FAppBackground = Colour(0xff1e2430);
    FEditorBackground = Colour(0xff0d1117);
    FKeyBackground = Colour(0xff2a3344);
    FKeyHoverBackground = Colour(0xff3a4a62);
    FKeyActiveBackground = Colour(0xff5b7a9e);
    FKeyBorder = Colour(0xff4a5568);
    FPrimaryText = Colour(0xffe8ecf0);
    FAccent = Colour(0xff6cb4ee);
    //
    setColour(ResizableWindow::backgroundColourId, FAppBackground);
    setColour(TextEditor::backgroundColourId, FEditorBackground);
    setColour(TextEditor::textColourId, FPrimaryText);
    setColour(TextEditor::outlineColourId, Colour(0xff3d4a5c));
    setColour(TextEditor::focusedOutlineColourId, FAccent);
    setColour(TextButton::buttonColourId, FKeyBackground);
    setColour(TextButton::buttonOnColourId, FKeyActiveBackground);
    setColour(TextButton::textColourOffId, FPrimaryText);
    setColour(TextButton::textColourOnId, FPrimaryText);
    setColour(Label::textColourId, FPrimaryText);
}
//
void TKeyboardLookAndFeel::drawButtonBackground(Graphics& g,
                                                Button& _button,
                                                const Colour& _backgroundColour,
                                                bool _isMouseOverButton,
                                                bool _isButtonDown)
{
    ignoreUnused(_backgroundColour);
    //
    const auto bounds = _button.getLocalBounds().toFloat().reduced(1.0f);
    const float cornerSize = 6.0f;
    Colour fillColour = FKeyBackground;
    //
    if (_button.getToggleState())
        fillColour = FKeyActiveBackground;
    else if (_isButtonDown)
        fillColour = FKeyActiveBackground.darker(0.15f);
    else if (_isMouseOverButton)
        fillColour = FKeyHoverBackground;
    //
    g.setColour(fillColour);
    g.fillRoundedRectangle(bounds, cornerSize);
    //
    g.setColour(FKeyBorder);
    g.drawRoundedRectangle(bounds, cornerSize, 1.0f);
}
//
Font TKeyboardLookAndFeel::getTextButtonFont(TextButton&, int _buttonHeight)
{
    const float fontHeight = static_cast<float>(_buttonHeight) * 0.34f;
    return Font(fontHeight);
}
//
void TKeyboardLookAndFeel::drawButtonText(Graphics& g,
                                          TextButton& _button,
                                          bool _shouldDrawButtonAsHighlighted,
                                          bool _shouldDrawButtonAsDown)
{
    ignoreUnused(_shouldDrawButtonAsHighlighted, _shouldDrawButtonAsDown);
    //
    g.setColour(_button.findColour(TextButton::textColourOffId));
    g.setFont(getTextButtonFont(_button, _button.getHeight()));
    g.drawFittedText(_button.getButtonText(),
                     _button.getLocalBounds().reduced(4, 2),
                     Justification::centred,
                     2);
}
//
void TKeyboardLookAndFeel::fillTextEditorBackground(Graphics& g, int _width, int _height, TextEditor& _editor)
{
    ignoreUnused(_editor);
    g.fillAll(FEditorBackground);
    //
    const auto bounds = Rectangle<int>(0, 0, _width, _height).toFloat().reduced(1.0f);
    g.setColour(Colour(0xff3d4a5c));
    g.drawRoundedRectangle(bounds, 8.0f, 1.0f);
}
//
void TKeyboardLookAndFeel::drawTextEditorOutline(Graphics& g, int _width, int _height, TextEditor& _editor)
{
    ignoreUnused(g, _width, _height, _editor);
}
