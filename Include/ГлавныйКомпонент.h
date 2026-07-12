#pragma once
//
// Файл: ГлавныйКомпонент.h
// Назначение: основной экран — заголовок, редактор текста, клавиатура, статус
//
#include "../JuceLibraryCode/JuceHeader.h"
#include "СтильКлавиатуры.h"
#include "ВиртуальнаяКлавиатура.h"
#include "ВспомогательныеСтроки.h"
//
class MainComponent : public Component
{
public:
    MainComponent(void);
    ~MainComponent(void) override;
    //
    void paint(Graphics& g) override;
    void resized(void) override;
    //
private:
    // Панель приветствия: блокирует рабочую область до нажатия «Начать работу»
    class TWelcomePanel : public Component
    {
    public:
        TWelcomePanel(void);
        //
        std::function<void(void)> FOnStart;
        //
        void paint(Graphics& g) override;
        void resized(void) override;
        //
    private:
        Label FWelcomeTitleLabel;
        Label FWelcomeMessageLabel;
        TextButton FStartButton;
    };
    //
    void updateStatusBar(void);
    void sendKeyPressToEditor(const KeyPress& _keyPress);
    void saveTextToFile(void);
    void setWorkAreaEnabled(bool _isEnabled);
    void enterWorkMode(void);
    //
    TKeyboardLookAndFeel FLookAndFeel;
    TextEditor FTextEditor;
    TVirtualKeyboard FVirtualKeyboard;
    Label FTitleLabel;
    Label FStatusLabel;
    TextButton FSaveButton;
    TWelcomePanel FWelcomePanel;
    bool FIsWorkModeActive;
    //
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
