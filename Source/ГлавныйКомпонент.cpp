#include "../Include/ГлавныйКомпонент.h"
//
MainComponent::TWelcomePanel::TWelcomePanel(void)
{
    setInterceptsMouseClicks(true, true);
    //
    FWelcomeTitleLabel.setText(strWelcomeTitle(), dontSendNotification);
    FWelcomeTitleLabel.setJustificationType(Justification::centred);
    FWelcomeTitleLabel.setFont(Font(28.0f, Font::bold));
    addAndMakeVisible(FWelcomeTitleLabel);
    //
    FWelcomeMessageLabel.setText(strWelcomeMessage(), dontSendNotification);
    FWelcomeMessageLabel.setJustificationType(Justification::centred);
    FWelcomeMessageLabel.setFont(Font(16.0f, Font::plain));
    addAndMakeVisible(FWelcomeMessageLabel);
    //
    FStartButton.setButtonText(strStartButton());
    FStartButton.onClick = [this]()
    {
        if (FOnStart != nullptr)
            FOnStart();
    };
    addAndMakeVisible(FStartButton);
}
//
void MainComponent::TWelcomePanel::paint(Graphics& g)
{
    g.fillAll(Colour(0xe61e2430));
    //
    const int panelWidth = 520;
    const int panelHeight = 260;
    const int panelX = (getWidth() - panelWidth) / 2;
    const int panelY = (getHeight() - panelHeight) / 2;
    const Rectangle<float> panelBounds(static_cast<float>(panelX),
                                       static_cast<float>(panelY),
                                       static_cast<float>(panelWidth),
                                       static_cast<float>(panelHeight));
    //
    g.setColour(Colour(0xff2a3344));
    g.fillRoundedRectangle(panelBounds, 12.0f);
    //
    g.setColour(Colour(0xff6cb4ee));
    g.drawRoundedRectangle(panelBounds, 12.0f, 2.0f);
}
//
void MainComponent::TWelcomePanel::resized(void)
{
    const int panelWidth = 520;
    const int panelHeight = 260;
    const int panelX = (getWidth() - panelWidth) / 2;
    const int panelY = (getHeight() - panelHeight) / 2;
    const int innerPadding = 24;
    const int buttonHeight = 40;
    const int buttonWidth = 200;
    const int titleHeight = 40;
    const int messageHeight = 80;
    const int contentX = panelX + innerPadding;
    const int contentWidth = panelWidth - innerPadding * 2;
    int currentY = panelY + innerPadding;
    //
    FWelcomeTitleLabel.setBounds(contentX, currentY, contentWidth, titleHeight);
    currentY += titleHeight + 12;
    //
    FWelcomeMessageLabel.setBounds(contentX, currentY, contentWidth, messageHeight);
    currentY += messageHeight + 24;
    //
    const int buttonX = panelX + (panelWidth - buttonWidth) / 2;
    FStartButton.setBounds(buttonX, currentY, buttonWidth, buttonHeight);
}
//
MainComponent::MainComponent(void)
    : FIsWorkModeActive(false)
{
    setLookAndFeel(&FLookAndFeel);
    setOpaque(true);
    setSize(1000, 720);
    //
    FTitleLabel.setText(strAppTitle(), dontSendNotification);
    FTitleLabel.setJustificationType(Justification::centredLeft);
    FTitleLabel.setFont(Font(20.0f, Font::bold));
    addAndMakeVisible(FTitleLabel);
    //
    FTextEditor.setMultiLine(true);
    FTextEditor.setReturnKeyStartsNewLine(true);
    FTextEditor.setScrollbarsShown(true);
    FTextEditor.setCaretVisible(true);
    FTextEditor.setPopupMenuEnabled(true);
    FTextEditor.setFont(Font("Consolas", 16.0f, Font::plain));
    FTextEditor.setText(strEditorPlaceholder());
    FTextEditor.onTextChange = [this]() { updateStatusBar(); };
    addAndMakeVisible(FTextEditor);
    //
    FStatusLabel.setJustificationType(Justification::centredLeft);
    addAndMakeVisible(FStatusLabel);
    //
    FSaveButton.setButtonText(strSaveButton());
    FSaveButton.onClick = [this]() { saveTextToFile(); };
    addAndMakeVisible(FSaveButton);
    //
    FVirtualKeyboard.FOnKeyPress = [this](const KeyPress& _keyPress) { sendKeyPressToEditor(_keyPress); };
    FVirtualKeyboard.FOnCapsLockToggle = [this]() { updateStatusBar(); };
    addAndMakeVisible(FVirtualKeyboard);
    //
    FWelcomePanel.FOnStart = [this]() { enterWorkMode(); };
    addAndMakeVisible(FWelcomePanel);
    //
    setWorkAreaEnabled(false);
    updateStatusBar();
}
//
MainComponent::~MainComponent(void)
{
    setLookAndFeel(nullptr);
}
//
void MainComponent::paint(Graphics& g)
{
    g.fillAll(findColour(ResizableWindow::backgroundColourId));
}
//
void MainComponent::resized(void)
{
    const int margin = 16;
    const int titleHeight = 32;
    const int statusHeight = 28;
    const int saveButtonWidth = 120;
    const int saveButtonHeight = 30;
    const int contentWidth = getWidth() - margin * 2;
    const int keyboardHeight = jmax(260, getHeight() / 2);
    const int editorHeight = getHeight() - margin * 2 - titleHeight - statusHeight - keyboardHeight - 12;
    int currentY = margin;
    //
    FTitleLabel.setBounds(margin, currentY, contentWidth - saveButtonWidth - 8, titleHeight);
    FSaveButton.setBounds(margin + contentWidth - saveButtonWidth, currentY, saveButtonWidth, saveButtonHeight);
    currentY += titleHeight + 8;
    //
    FTextEditor.setBounds(margin, currentY, contentWidth, jmax(120, editorHeight));
    currentY += jmax(120, editorHeight) + 8;
    //
    FStatusLabel.setBounds(margin, currentY, contentWidth, statusHeight);
    currentY += statusHeight + 8;
    //
    FVirtualKeyboard.setBounds(margin, currentY, contentWidth, keyboardHeight);
    //
    FWelcomePanel.setBounds(getLocalBounds());
    FWelcomePanel.toFront(false);
}
//
void MainComponent::setWorkAreaEnabled(bool _isEnabled)
{
    FTextEditor.setEnabled(_isEnabled);
    FVirtualKeyboard.setEnabled(_isEnabled);
    FSaveButton.setEnabled(_isEnabled);
    FStatusLabel.setEnabled(_isEnabled);
}
//
void MainComponent::enterWorkMode(void)
{
    if (FIsWorkModeActive)
        return;
    //
    FIsWorkModeActive = true;
    FWelcomePanel.setVisible(false);
    setWorkAreaEnabled(true);
    FTextEditor.setText(String());
    FTextEditor.grabKeyboardFocus();
    updateStatusBar();
}
//
void MainComponent::updateStatusBar(void)
{
    const int textLength = FTextEditor.getText().length();
    const String capsLockText = FVirtualKeyboard.isCapsLockOn() ? strCapsLockOn() : strCapsLockOff();
    const String statusText = capsLockText + strCharCountPrefix() + String(textLength);
    //
    FStatusLabel.setText(statusText, dontSendNotification);
}
//
void MainComponent::sendKeyPressToEditor(const KeyPress& _keyPress)
{
    FTextEditor.grabKeyboardFocus();
    FTextEditor.keyPressed(_keyPress);
    updateStatusBar();
}
//
void MainComponent::saveTextToFile(void)
{
    auto fileChooser = std::make_shared<FileChooser>(strSaveDialogTitle(), File(), "*.txt");
    //
    const int chooserFlags = FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles;
    //
    fileChooser->launchAsync(chooserFlags, [this, fileChooser](const FileChooser& _chooser)
    {
        const File targetFile = _chooser.getResult();
        //
        if (targetFile == File())
            return;
        //
        targetFile.replaceWithText(FTextEditor.getText());
    });
}
