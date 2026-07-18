#pragma once
//
// Файл: ГлавноеОкно.h
// Назначение: главное окно приложения (рамка, заголовок, кнопки свернуть/закрыть)
//
#include "../JuceLibraryCode/JuceHeader.h"
#include "ГлавныйКомпонент.h"
//
/**
 * @class MainFrame
 * @brief Главное окно приложения (обёртка ОС вокруг MainComponent).
 *
 * Наследуется от juce::DocumentWindow — стандартного окна JUCE с рамкой,
 * заголовком и системными кнопками (свернуть/закрыть).
 */
class MainFrame : public DocumentWindow
{
public:
    /**
     * @brief Конструктор. Создаёт окно с заданным заголовком и устанавливает
     *        MainComponent в качестве содержимого окна.
     * @param name Текст заголовка окна.
     */
    MainFrame(const String& name);
    //
    /// @brief Обрабатывает нажатие системной кнопки закрытия окна.
    void closeButtonPressed(void) override { JUCEApplication::getInstance()->systemRequestedQuit(); }
    //
    /**
     * @brief Возвращает ссылку на содержимое окна как MainComponent.
     * @return Ссылка на объект MainComponent, размещённый в этом окне.
     */
    MainComponent& getMainComponent(void) { return *dynamic_cast<MainComponent*> (getContentComponent()); }
    //
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainFrame)
};