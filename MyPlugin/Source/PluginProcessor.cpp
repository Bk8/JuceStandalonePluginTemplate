/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyPluginAudioProcessor::MyPluginAudioProcessor()
{
}

MyPluginAudioProcessor::~MyPluginAudioProcessor()
{
}

//==============================================================================
const String MyPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int MyPluginAudioProcessor::getNumParameters()
{
    return 0;
}

float MyPluginAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void MyPluginAudioProcessor::setParameter (int index, float newValue)
{
}

const String MyPluginAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String MyPluginAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String MyPluginAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String MyPluginAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool MyPluginAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool MyPluginAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool MyPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MyPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MyPluginAudioProcessor::silenceInProducesSilenceOut() const
{
    return true;
}

double MyPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MyPluginAudioProcessor::getNumPrograms()
{
    return 0;
}

int MyPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MyPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String MyPluginAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void MyPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MyPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MyPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void MyPluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);
        
        // ..do something to the data...
        for (int i = 0; i < buffer.getNumSamples(); i++) {
            // .. this loop is for iterating over all samples
        }
    }

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool MyPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MyPluginAudioProcessor::createEditor()
{
    return new MyPluginPluginEditor(this);
}

//==============================================================================
void MyPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MyPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MyPluginAudioProcessor();
}
