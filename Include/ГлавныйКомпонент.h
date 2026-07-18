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
/**
 * @class MainComponent
 * @brief Главный экран приложения «Виртуальная клавиатура».
 *
 * Содержит заголовок, поле ввода текста, статус-бар, кнопку сохранения и виртуальную
 * клавиатуру. До нажатия кнопки «Начать работу» поверх всего показана приветственная
 * панель (TWelcomePanel), блокирующая ввод.
 */
class MainComponent : public Component
{
public:
    /**
     * @brief Конструктор. Создаёт и настраивает все дочерние компоненты экрана,
     *        подписывается на их колбэки.
     */
    MainComponent(void);
    //
    /**
     * @brief Деструктор. Отвязывает LookAndFeel перед уничтожением.
     */
    ~MainComponent(void) override;
    //
    /**
     * @brief Отрисовывает фон главного экрана.
     * @param g Ссылка на объект Graphics для рисования.
     */
    void paint(Graphics& g) override;
    //
    /**
     * @brief Располагает все дочерние компоненты при изменении размера окна.
     */
    void resized(void) override;
    //
private:
    /**
     * @class TWelcomePanel
     * @brief Приветственная панель, блокирующая рабочую область до нажатия «Начать работу».
     */
    class TWelcomePanel : public Component
    {
    public:
        /**
         * @brief Конструктор. Настраивает заголовок, сообщение и кнопку старта.
         */
        TWelcomePanel(void);
        //
        /**
         * @brief Колбэк, вызываемый при нажатии кнопки «Начать работу».
         */
        std::function<void(void)> FOnStart;
        //
        /**
         * @brief Отрисовывает затемнение фона и саму карточку панели.
         * @param g Ссылка на объект Graphics для рисования.
         */
        void paint(Graphics& g) override;
        //
        /**
         * @brief Располагает заголовок, сообщение и кнопку внутри панели.
         */
        void resized(void) override;
        //
    private:
        Label FWelcomeTitleLabel;     ///< Заголовок приветственного экрана
        Label FWelcomeMessageLabel;   ///< Пояснительный текст приветственного экрана
        TextButton FStartButton;      ///< Кнопка перехода в рабочий режим
    };
    //
    /**
     * @brief Пересобирает текст статус-бара (раскладка, CapsLock, количество символов).
     */
    void updateStatusBar(void);
    //
    /**
     * @brief Передаёт полученный от виртуальной клавиатуры KeyPress в текстовое поле,
     *        симулируя настоящее нажатие клавиши.
     * @param _keyPress Событие нажатия клавиши.
     */
    void sendKeyPressToEditor(const KeyPress& _keyPress);
    //
    /**
     * @brief Открывает асинхронный диалог сохранения и записывает текст в выбранный файл.
     */
    void saveTextToFile(void);
    //
    /**
     * @brief Включает или выключает интерактивность рабочей области экрана.
     * @param _isEnabled true — включить, false — выключить.
     */
    void setWorkAreaEnabled(bool _isEnabled);
    //
    /**
     * @brief Переводит приложение из приветственного экрана в рабочий режим.
     */
    void enterWorkMode(void);
    //
    TKeyboardLookAndFeel FLookAndFeel;   ///< Пользовательский стиль оформления интерфейса
    TextEditor FTextEditor;               ///< Поле ввода и редактирования текста
    TVirtualKeyboard FVirtualKeyboard;    ///< Панель виртуальной клавиатуры
    Label FTitleLabel;                     ///< Заголовок приложения
    Label FStatusLabel;                    ///< Статус-строка (раскладка, CapsLock, счётчик символов)
    TextButton FSaveButton;                ///< Кнопка сохранения текста в файл
    TWelcomePanel FWelcomePanel;           ///< Приветственная панель
    bool FIsWorkModeActive;                 ///< Флаг: активен ли рабочий режим
    //
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};