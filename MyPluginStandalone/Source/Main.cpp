/*
 ==============================================================================
 
 This file was auto-generated by the Introjucer!
 
 It contains the basic startup code for a Juce application.
 
 Some Code of this File is borrowed from: https://github.com/klangfreund/LUFSMeter
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"
// #include "MainComponent.h"
// #include "../../../libraries/juce/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h"
#include "juce_StandaloneFilterWindow.h"


//==============================================================================
class MyPluginStandaloneApplication  : public JUCEApplication
{
public:
    //==============================================================================
    MyPluginStandaloneApplication() {}
    
    const String getApplicationName()       { return ProjectInfo::projectName; }
    const String getApplicationVersion()    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed()       { return true; }
    
    //==============================================================================
    void initialise (const String& commandLine)
    {
        // This method is where you should put your application's initialisation code..
        
        standaloneFilterWindow = new StandaloneFilterWindow("MyPlugin", Colours::lightgrey, nullptr);
        standaloneFilterWindow->setTitleBarButtonsRequired (DocumentWindow::allButtons, false);
        standaloneFilterWindow->setVisible (true);
        standaloneFilterWindow->setResizable (true, true);
    }
    
    void shutdown()
    {
        // Add your application's shutdown code here..
        
        standaloneFilterWindow = nullptr; // (deletes our window)
    }
    
    //==============================================================================
    void systemRequestedQuit()
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }
    
    void anotherInstanceStarted (const String& commandLine)
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }
    
    //==============================================================================
    
private:
    ScopedPointer<StandaloneFilterWindow> standaloneFilterWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (MyPluginStandaloneApplication)
