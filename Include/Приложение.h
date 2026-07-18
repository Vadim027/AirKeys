#pragma once
//
// Файл: Приложение.h
// Назначение: запуск и завершение программы (точка входа JUCE)
//
#include "../JuceLibraryCode/JuceHeader.h"
#include "ВспомогательныеСтроки.h"
#include "ГлавноеОкно.h"
//
/**
 * @class PracticeApplication
 * @brief Точка входа приложения. Создаёт главное окно при запуске
 *        и корректно освобождает его при завершении работы.
 */
class PracticeApplication : public JUCEApplication
{
public:
    PracticeApplication(void) {}
    ~PracticeApplication(void) override {}
    //
    /// @brief Название приложения, отображаемое в заголовке окна.
    const String getApplicationName(void) override { return strAppTitle(); }
    //
    /// @brief Версия приложения (берётся из автогенерируемого ProjectInfo).
    const String getApplicationVersion(void) override { return ProjectInfo::versionString; }
    //
    /// @brief Разрешает запуск нескольких экземпляров приложения одновременно.
    bool moreThanOneInstanceAllowed(void) override { return true; }
    //
    /**
     * @brief Вызывается JUCE один раз при старте программы — создаёт главное окно.
     */
    void initialise(const String&) override
    {
        mainFrame.reset(new MainFrame(getApplicationName()));
    }
    //
    /// @brief Вызывается при завершении работы приложения — освобождает главное окно.
    void shutdown(void) override { mainFrame = nullptr; }
    //
    /// @brief Вызывается, если система запрашивает закрытие приложения.
    void systemRequestedQuit(void) override { quit(); }
    //
    /// @brief Вызывается при попытке запустить второй экземпляр приложения (не используется).
    void anotherInstanceStarted(const String&) override {}
    //
private:
    std::unique_ptr<MainFrame> mainFrame; ///< Главное окно приложения
};
//
START_JUCE_APPLICATION(PracticeApplication)