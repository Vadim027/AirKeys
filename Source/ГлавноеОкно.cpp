#include "../JuceLibraryCode/JuceHeader.h"
#include "../Include/ГлавноеОкно.h"
#include "../Include/Приложение.h"
//
MainFrame::MainFrame(const String& name)
   : DocumentWindow(name, Desktop::getInstance().getDefaultLookAndFeel()
      .findColour(ResizableWindow::backgroundColourId),
      DocumentWindow::allButtons)
{
   setUsingNativeTitleBar(true);
   setResizable(false, true);
   centreWithSize(1000, 720);
   //
   setContentOwned(new MainComponent(), false);
   setVisible(true);
}
