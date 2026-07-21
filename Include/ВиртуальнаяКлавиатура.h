#pragma once
//
// Файл: ВиртуальнаяКлавиатура.h
// Назначение: панель с клавишами, обработка KeyPress, переключение раскладки RU/EN
//
#include "../JuceLibraryCode/JuceHeader.h"
#include "ВспомогательныеСтроки.h"
//
/**
 * @class TVirtualKeyboard
 * @brief Компонент-панель виртуальной клавиатуры.
 *
 * Создаёт набор кнопок-клавиш по данным статических таблиц раскладки (русской и английской),
 * обрабатывает клики по клавишам и передаёт события наружу через колбэки (FOnKeyPress,
 * FOnCapsLockToggle, FOnLayoutChange), не имея прямой связи с текстовым полем, в которое
 * вводится текст.
 */
class TVirtualKeyboard : public Component
{
public:
    /**
     * @brief Конструктор. Создаёт все кнопки текущей (русской) раскладки и располагает их.
     */
    TVirtualKeyboard(void);
    //
    /**
     * @brief Колбэк, вызываемый при нажатии обычной клавиши (символ, Backspace, Space, Enter).
     * @param KeyPress Описание нажатой клавиши для передачи в TextEditor::keyPressed().
     */
    std::function<void(const KeyPress&)> FOnKeyPress;
    //
    /**
     * @brief Колбэк, вызываемый при переключении состояния CapsLock.
     */
    std::function<void(void)> FOnCapsLockToggle;
    //
    /**
     * @brief Колбэк, вызываемый при смене раскладки клавиатуры (RU/EN).
     */
    std::function<void(void)> FOnLayoutChange;
    //
    /**
     * @brief Устанавливает состояние CapsLock и обновляет подписи/шорткаты всех кнопок.
     * @param _isCapsLockOn true — включить CapsLock, false — выключить.
     */
    void setCapsLockState(bool _isCapsLockOn);
    //
    /**
     * @brief Возвращает текущее состояние CapsLock.
     * @return true, если CapsLock включён.
     */
    bool isCapsLockOn(void) const { return FCapsLockOn; }
    //
    /**
     * @brief Проверяет, активна ли сейчас английская раскладка.
     * @return true, если активна английская раскладка; false — если русская.
     */
    bool isEnglishLayout(void) const;
    //
    /**
     * @brief Отрисовывает фон панели клавиатуры.
     * @param g Ссылка на объект Graphics для рисования.
     */
    void paint(Graphics& g) override;
    //
    /**
     * @brief Пересчитывает расположение всех клавиш при изменении размера компонента.
     */
    void resized(void) override;
    //
private:
    /**
     * @brief Тип (роль) клавиши на виртуальной клавиатуре.
     */
    enum class TKeyKind
    {
        characterKey,    ///< Обычный символ (буква, цифра, спецсимвол)
        backspaceKey,     ///< Клавиша удаления символа
        capsLockKey,      ///< Клавиша переключения регистра
        spaceKey,         ///< Клавиша пробела
        enterKey,         ///< Клавиша новой строки
        layoutSwitchKey   ///< Клавиша переключения раскладки RU/EN
    };
    //
    /**
     * @brief Доступные раскладки клавиатуры.
     */
    enum class TLayoutKind
    {
        russian,  ///< Русская раскладка (кириллица)
        english   ///< Английская раскладка (латиница)
    };
    //
    /**
     * @struct TKeySpec
     * @brief Описание одной клавиши раскладки (данные, а не поведение).
     */
    struct TKeySpec
    {
        const wchar_t* FText;       ///< Текст на кнопке в обычном регистре
        const wchar_t* FTextUpper;  ///< Текст в верхнем регистре (nullptr, если нет заглавного варианта)
        TKeyKind FKind;              ///< Тип (роль) клавиши
        int FWidthUnits;             ///< Ширина кнопки в условных единицах
    };
    //
    /**
     * @class TVirtualKeyButton
     * @brief Кнопка-клавиша виртуальной клавиатуры, расширяет juce::TextButton
     *        собственными полями: типом клавиши и связанным KeyPress.
     */
    class TVirtualKeyButton : public TextButton
    {
    public:
        /**
         * @brief Конструктор кнопки-клавиши.
         * @param _buttonText Текст, отображаемый на кнопке.
         * @param _keyPress KeyPress, который будет привязан как физический шорткат (если валиден).
         * @param _kind Тип (роль) клавиши.
         */
        TVirtualKeyButton(const String& _buttonText, const KeyPress& _keyPress, TKeyKind _kind);
        //
        TKeyKind FKind;             ///< Тип (роль) клавиши
        KeyPress FKeyPress;          ///< Связанный физический KeyPress
        bool FIsCapsLockActive;      ///< Актуально только для кнопки CapsLock — её текущее состояние
        //
        /**
         * @brief Обновляет визуальное состояние клавиши CapsLock.
         * @param _isCapsLockOn Текущее состояние CapsLock.
         */
        void updateCapsLockVisual(bool _isCapsLockOn);
    };
    //
    /**
     * @class TLayoutSwitchButton
     * @brief Клавиша выбора раскладки: при удержании показывает меню RU/EN.
     */
    class TLayoutSwitchButton : public TVirtualKeyButton, private Timer
    {
    public:
        TLayoutSwitchButton(TVirtualKeyboard& _owner, const String& _buttonText);
        //
        void mouseDown(const MouseEvent& _event) override;
        void mouseUp(const MouseEvent& _event) override;
        //
    private:
        void timerCallback(void) override;
        //
        TVirtualKeyboard& FKeyboardOwner;
        bool FLongPressHandled;
        static const int FLongPressDelayMs = 450;
    };
    //
    /**
     * @brief Создаёт кнопки текущей активной раскладки (используется и в конструкторе,
     *        и при смене раскладки).
     */
    void createKeys(void);
    //
    /**
     * @brief Вычисляет и устанавливает позиции/размеры всех кнопок по рядам.
     */
    void layoutKeys(void);
    //
    /**
     * @brief Переключает раскладку на заданную и пересоздаёт кнопки.
     * @param _layout Целевая раскладка.
     */
    void setLayout(TLayoutKind _layout);
    //
    /**
     * @brief Показывает всплывающее меню выбора раскладки RU/EN.
     * @param _targetComponent Компонент, рядом с которым открывается меню.
     */
    void showLayoutSelectionMenu(Component* _targetComponent);
    //
    /**
     * @brief Строит объект KeyPress (физический аналог) для заданной клавиши.
     * @param _keySpec Описание клавиши.
     * @return Соответствующий KeyPress (может быть невалидным для CapsLock/переключателя раскладки).
     */
    KeyPress makeKeyPressForSpec(const TKeySpec& _keySpec) const;
    //
    /**
     * @brief Строит текст подписи для кнопки с учётом текущего состояния CapsLock.
     * @param _keySpec Описание клавиши.
     * @return Готовая строка juce::String для отображения на кнопке.
     */
    String makeLabelForSpec(const TKeySpec& _keySpec) const;
    //
    /**
     * @brief Обрабатывает клик по любой кнопке клавиатуры и маршрутизирует его
     *        в зависимости от типа клавиши (CapsLock / смена раскладки / обычная клавиша).
     * @param _button Указатель на нажатую кнопку.
     */
    void handleKeyButtonClick(TVirtualKeyButton* _button);
    //
    /**
     * @brief Обновляет зажатое состояние клавиши CapsLock.
     */
    void updateAllToggleVisuals(void);
    //
    /// @brief Возвращает указатель на массив данных текущей активной раскладки.
    const TKeySpec* getActiveLayoutData(void) const;
    //
    /// @brief Возвращает количество клавиш в текущей активной раскладке.
    int getActiveLayoutSize(void) const;
    //
    /// @brief Возвращает массив индексов начала рядов для текущей активной раскладки.
    const int* getActiveRowStarts(void) const;
    //
    /// @brief Возвращает количество рядов в текущей активной раскладке.
    int getActiveRowCount(void) const;
    //
    bool FCapsLockOn;                          ///< Текущее состояние CapsLock
    TLayoutKind FCurrentLayout;                 ///< Текущая активная раскладка
    int FKeyGap;                                ///< Горизонтальный зазор между кнопками, px
    int FRowGap;                                ///< Вертикальный зазор между рядами, px
    OwnedArray<TVirtualKeyButton> FKeyButtons;  ///< Все кнопки текущей активной раскладки
    //
    static const TKeySpec FKeyboardLayoutRussian[];  ///< Данные русской раскладки
    static const int FKeyboardLayoutRussianSize;      ///< Количество клавиш в русской раскладке
    static const int FRowStartsRussian[];              ///< Индексы начала рядов (русская раскладка)
    static const int FRowCountRussian;                  ///< Количество рядов (русская раскладка)
    //
    static const TKeySpec FKeyboardLayoutEnglish[];   ///< Данные английской раскладки
    static const int FKeyboardLayoutEnglishSize;       ///< Количество клавиш в английской раскладке
    static const int FRowStartsEnglish[];               ///< Индексы начала рядов (английская раскладка)
    static const int FRowCountEnglish;                   ///< Количество рядов (английская раскладка)
    //
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TVirtualKeyboard)
};