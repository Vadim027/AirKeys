#pragma once
//
// Файл: Приложение.h
// Назначение: запуск и завершение программы (точка входа JUCE)
//
#include "../JuceLibraryCode/JuceHeader.h"
#include "ВспомогательныеСтроки.h"
#include "ГлавноеОкно.h"
//
class PracticeApplication : public JUCEApplication
{
public:
   PracticeApplication(void) {}
   ~PracticeApplication(void) override {}
   //
   const String getApplicationName(void) override { return strAppTitle(); }
   const String getApplicationVersion(void) override { return ProjectInfo::versionString; }
   bool moreThanOneInstanceAllowed(void) override { return true; }
   //
   void initialise(const String&) override
   {
      mainFrame.reset(new MainFrame(getApplicationName()));
   }
   //
   void shutdown(void) override { mainFrame = nullptr; }
   //
   void systemRequestedQuit(void) override { quit(); }
   void anotherInstanceStarted(const String&) override {}
   //
private:
   std::unique_ptr<MainFrame> mainFrame;
};
//
START_JUCE_APPLICATION(PracticeApplication)
