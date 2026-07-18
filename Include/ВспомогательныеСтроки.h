#pragma once
//
// Файл: ВспомогательныеСтроки.h
// Назначение: корректный вывод русского текста в интерфейсе JUCE (Windows)
//
#include <string>
#include "../JuceLibraryCode/JuceHeader.h"
// std::wstring text(L"...");  juce::String(text.c_str());
inline String makeJuceString(const wchar_t* _text)
{
    const std::wstring wideText(_text);
    return String(wideText.c_str());
}
//
inline String strAppTitle(void)
{
    const std::wstring text(L"Виртуальная клавиатура");
    return String(text.c_str());
}
//
inline String strSaveButton(void)
{
    const std::wstring text(L"Сохранить");
    return String(text.c_str());
}
//
inline String strCapsLockOn(void)
{
    const std::wstring text(L"CapsLock: ВКЛ");
    return String(text.c_str());
}
//
inline String strCapsLockOff(void)
{
    const std::wstring text(L"CapsLock: ВЫКЛ");
    return String(text.c_str());
}
//
inline String strCharCountPrefix(void)
{
    const std::wstring text(L"          Символов: ");
    return String(text.c_str());
}
//
inline String strSaveDialogTitle(void)
{
    const std::wstring text(L"Сохранить текст");
    return String(text.c_str());
}
//
inline String strWelcomeTitle(void)
{
    const std::wstring text(L"Добро пожаловать!");
    return String(text.c_str());
}
//
inline String strWelcomeMessage(void)
{
    const std::wstring text(L"Приложение «Виртуальная клавиатура».\r\n"
                            L"Нажмите кнопку ниже, чтобы перейти к вводу и редактированию текста.");
    return String(text.c_str());
}
//
inline String strStartButton(void)
{
    const std::wstring text(L"Начать работу");
    return String(text.c_str());
}
//
inline String strEditorPlaceholder(void)
{
    const std::wstring text(L"Введите текст с помощью виртуальной клавиатуры...");
    return String(text.c_str());
}

inline String strLayoutRussian(void)
{
    const std::wstring text(L"Раскладка: RU");
    return String(text.c_str());
}
//
inline String strLayoutEnglish(void)
{
    const std::wstring text(L"Раскладка: EN");
    return String(text.c_str());
}
