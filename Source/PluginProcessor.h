/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class AufgabeAudioProcessor  : public AudioProcessor,
                               public Timer
{
public:
    //==============================================================================
    AufgabeAudioProcessor();
    ~AufgabeAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //===============================================================================
    void timerCallback() override;
    
    //===============================================================================
    /* This methods return the current RMS value from every channel */
    float getCh1RMS();
    float getCh2RMS();
    float getCh3RMS();
    float getCh4RMS();
    float getCh5RMS();
    float getCh6RMS();
    float getCh7RMS();
    float getCh8RMS();
    float getCh9RMS();
    float getCh10RMS();
    float getCh11RMS();
    float getCh12RMS();
    float getCh13RMS();
    float getCh14RMS();
    float getCh15RMS();
    float getCh16RMS();
    
    //===============================================================================
    /* This methods return the current RMS value from ALL channel */
    void getRMSValuesForAllChannels(AudioBuffer<float>& buffer);
    
    //===============================================================================
    /* This methods return the JSON message will all the values that should be send in the POST request */
    String jsonMessage();
    
    //===============================================================================
    /* Sends a POST request */
    void POST();
    
    //===============================================================================
    /* This method change the bool associated with each channel when the Led_ TextButton in one channel is clicked */
    void sendChanger(String);
    
    
    URL url;
    
private:
    
    //===============================================================================
    /* Holds the value of each channel */
    float ch1RMS{0.0f};
    float ch2RMS{0.0f};
    float ch3RMS{0.0f};
    float ch4RMS{0.0f};
    float ch5RMS{0.0f};
    float ch6RMS{0.0f};
    float ch7RMS{0.0f};
    float ch8RMS{0.0f};
    float ch9RMS{0.0f};
    float ch10RMS{0.0f};
    float ch11RMS{0.0f};
    float ch12RMS{0.0f};
    float ch13RMS{0.0f};
    float ch14RMS{0.0f};
    float ch15RMS{0.0f};
    float ch16RMS{0.0f};
    
    
    //===============================================================================
    /* Flags whether the current value of a channel should be sended or not */
    bool sendCh1 {false};
    bool sendCh2 {false};
    bool sendCh3 {false};
    bool sendCh4 {false};
    bool sendCh5 {false};
    bool sendCh6 {false};
    bool sendCh7 {false};
    bool sendCh8 {false};
    bool sendCh9 {false};
    bool sendCh10 {false};
    bool sendCh11 {false};
    bool sendCh12 {false};
    bool sendCh13 {false};
    bool sendCh14 {false};
    bool sendCh15 {false};
    bool sendCh16 {false};
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AufgabeAudioProcessor)
};
