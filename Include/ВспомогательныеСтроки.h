#pragma once
//
// Файл: ВспомогательныеСтроки.h
// Назначение: корректный вывод русского текста в интерфейсе JUCE (Windows)
//
#include <string>
#include "../JuceLibraryCode/JuceHeader.h"
//
/**
 * @brief Преобразует широкую C-строку в juce::String с корректным отображением
 *        русских символов на Windows (обход особенностей кодировок JUCE).
 * @param _text Исходная строка в формате const wchar_t*.
 * @return Готовая строка juce::String.
 */
inline String makeJuceString(const wchar_t* _text)
{
    const std::wstring wideText(_text);
    return String(wideText.c_str());
}
//
/// @brief Заголовок приложения, отображаемый в шапке окна.
inline String strAppTitle(void)
{
    const std::wstring text(L"Виртуальная клавиатура");
    return String(text.c_str());
}
//
/// @brief Текст на кнопке сохранения текста в файл.
inline String strSaveButton(void)
{
    const std::wstring text(L"Сохранить");
    return String(text.c_str());
}
//
/// @brief Текст статус-бара при включённом CapsLock.
inline String strCapsLockOn(void)
{
    const std::wstring text(L"CapsLock: ВКЛ");
    return String(text.c_str());
}
//
/// @brief Текст статус-бара при выключенном CapsLock.
inline String strCapsLockOff(void)
{
    const std::wstring text(L"CapsLock: ВЫКЛ");
    return String(text.c_str());
}
//
/// @brief Префикс перед счётчиком символов в статус-баре.
inline String strCharCountPrefix(void)
{
    const std::wstring text(L"          Символов: ");
    return String(text.c_str());
}
//
/// @brief Заголовок диалогового окна сохранения файла.
inline String strSaveDialogTitle(void)
{
    const std::wstring text(L"Сохранить текст");
    return String(text.c_str());
}
//
/// @brief Заголовок приветственного экрана.
inline String strWelcomeTitle(void)
{
    const std::wstring text(L"Добро пожаловать!");
    return String(text.c_str());
}
//
/// @brief Пояснительное сообщение на приветственном экране.
inline String strWelcomeMessage(void)
{
    const std::wstring text(L"Приложение «Виртуальная клавиатура».\r\n"
        L"Нажмите кнопку ниже, чтобы перейти к вводу и редактированию текста.");
    return String(text.c_str());
}
//
/// @brief Текст на кнопке перехода в рабочий режим.
inline String strStartButton(void)
{
    const std::wstring text(L"Начать работу");
    return String(text.c_str());
}
//
/// @brief Текст-заглушка в текстовом поле до начала ввода.
inline String strEditorPlaceholder(void)
{
    const std::wstring text(L"Введите текст с помощью виртуальной клавиатуры...");
    return String(text.c_str());
}
//
/// @brief Текст статус-бара при активной русской раскладке.
inline String strLayoutRussian(void)
{
    const std::wstring text(L"Раскладка: RU");
    return String(text.c_str());
}
//
/// @brief Текст статус-бара при активной английской раскладке.
inline String strLayoutEnglish(void)
{
    const std::wstring text(L"Раскладка: EN");
    return String(text.c_str());
}