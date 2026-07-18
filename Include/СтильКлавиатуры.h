#pragma once
//
// Файл: СтильКлавиатуры.h
// Назначение: пользовательский внешний вид кнопок, редактора и фона
//
#include "../JuceLibraryCode/JuceHeader.h"
//
/**
 * @class TKeyboardLookAndFeel
 * @brief Пользовательский стиль оформления (LookAndFeel) приложения.
 *
 * Переопределяет отрисовку кнопок и текстового редактора JUCE, задавая
 * нешаблонную цветовую схему интерфейса (тёмная тема).
 */
class TKeyboardLookAndFeel : public LookAndFeel_V4
{
public:
    /**
     * @brief Конструктор. Инициализирует палитру цветов и применяет её
     *        ко всем стандартным элементам JUCE через setColour().
     */
    TKeyboardLookAndFeel(void);
    //
    /**
     * @brief Отрисовывает фон кнопки с учётом состояния (наведение/нажатие/toggle).
     * @param g Ссылка на объект Graphics.
     * @param _button Кнопка, для которой рисуется фон.
     * @param _backgroundColour Цвет фона по умолчанию (не используется напрямую).
     * @param _isMouseOverButton true, если курсор наведён на кнопку.
     * @param _isButtonDown true, если кнопка сейчас нажата.
     */
    void drawButtonBackground(Graphics& g,
        Button& _button,
        const Colour& _backgroundColour,
        bool _isMouseOverButton,
        bool _isButtonDown) override;
    //
    /**
     * @brief Возвращает шрифт для текста на кнопке (кнопка «Сохранить» получает
     *        увеличенный фиксированный размер по своему ComponentID).
     * @param _button Кнопка, для которой запрашивается шрифт.
     * @param _buttonHeight Текущая высота кнопки в пикселях.
     * @return Объект Font с рассчитанным размером.
     */
    Font getTextButtonFont(TextButton& _button, int _buttonHeight) override;
    //
    /**
     * @brief Отрисовывает текст на кнопке.
     * @param g Ссылка на объект Graphics.
     * @param _button Кнопка, текст которой рисуется.
     * @param _shouldDrawButtonAsHighlighted true, если кнопка подсвечена.
     * @param _shouldDrawButtonAsDown true, если кнопка нажата.
     */
    void drawButtonText(Graphics& g,
        TextButton& _button,
        bool _shouldDrawButtonAsHighlighted,
        bool _shouldDrawButtonAsDown) override;
    //
    /**
     * @brief Отрисовывает фон текстового поля.
     * @param g Ссылка на объект Graphics.
     * @param _width Ширина поля.
     * @param _height Высота поля.
     * @param _editor Ссылка на редактируемый TextEditor.
     */
    void fillTextEditorBackground(Graphics& g, int _width, int _height, TextEditor& _editor) override;
    //
    /**
     * @brief Отрисовывает обводку текстового поля (в данной реализации отключена).
     * @param g Ссылка на объект Graphics.
     * @param _width Ширина поля.
     * @param _height Высота поля.
     * @param _editor Ссылка на редактируемый TextEditor.
     */
    void drawTextEditorOutline(Graphics& g, int _width, int _height, TextEditor& _editor) override;
    //
private:
    Colour FAppBackground;        ///< Цвет фона приложения
    Colour FEditorBackground;     ///< Цвет фона текстового поля
    Colour FKeyBackground;        ///< Цвет фона обычной клавиши
    Colour FKeyHoverBackground;   ///< Цвет фона клавиши при наведении
    Colour FKeyActiveBackground;  ///< Цвет фона активной/нажатой клавиши
    Colour FKeyBorder;            ///< Цвет обводки клавиши
    Colour FPrimaryText;          ///< Основной цвет текста
    Colour FAccent;                ///< Акцентный цвет (например, рамка при фокусе)
};