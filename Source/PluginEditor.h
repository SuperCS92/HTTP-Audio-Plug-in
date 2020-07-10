/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Channel.h"

//==============================================================================
/**
*/
class AufgabeAudioProcessorEditor  : public AudioProcessorEditor,
                                     public Timer,
                                     private ComboBox::Listener
{
public:
    AufgabeAudioProcessorEditor (AufgabeAudioProcessor&);
    ~AufgabeAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    //==============================================================================
    void timerCallback() override;
    
    //==============================================================================
    /* Receives the current RMS value of a given channel, turns it to decibels and then String */
    String valueToString(float);
    
    //==============================================================================
    /* Call valueToString() for all channels */
    void valueToStringForAllChannels(String&, String&, String&, String&, String&, String&, String&, String&, String&, String&, String&, String&,String&, String&, String&, String&);
    
    //==============================================================================
    /* Call updateLevel() for all channels */
    void updateLevelsForAllChannels(String&, String&, String&, String&, String&, String&, String&, String&, String&, String&, String&, String&,String&, String&, String&, String&);
    
    //==============================================================================
    /* Restart the timer and set the new interval between POST request */
    void comboBoxChanged(ComboBox*) override;
    
    //==============================================================================
    /* Returns the current value of the Led_ TextButton, if true the value will be send in the POST request  */
    bool sendChannel(Channel*);

    //==============================================================================
    /* Change the state of ALL Led_ TextButton from true to false or viceversa,
     this method is called when the SendAllButton is clicked */
    void sendAll();
    
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AufgabeAudioProcessor& processor;
    
    //==============================================================================
    /* Instantiation of 16 channels */
    Channel ch1 {processor,"Ch1"};
    Channel ch2 {processor,"Ch2"};
    Channel ch3 {processor,"Ch3"};
    Channel ch4 {processor,"Ch4"};
    Channel ch5 {processor,"Ch5"};
    Channel ch6 {processor,"Ch6"};
    Channel ch7 {processor,"Ch7"};
    Channel ch8 {processor,"Ch8"};
    Channel ch9 {processor,"Ch9"};
    Channel ch10 {processor,"Ch10"};
    Channel ch11 {processor,"Ch11"};
    Channel ch12 {processor,"Ch12"};
    Channel ch13 {processor,"Ch13"};
    Channel ch14 {processor,"Ch14"};
    Channel ch15 {processor,"Ch15"};
    Channel ch16 {processor,"Ch16"};
    
    //==============================================================================
    /* Each String holds the current value of each channel */
    String levelCh1, levelCh2, levelCh3, levelCh4,
           levelCh5, levelCh6, levelCh7, levelCh8,
           levelCh9, levelCh10, levelCh11, levelCh12,
           levelCh13, levelCh14, levelCh15, levelCh16;
    
    TextEditor urlBox;                          // Here will be the url where the POST request will be sended
    TextButton fetchButton { "Change URL " };   
    TextButton SendAllButton { "Send All" };
    
    ComboBox timerMenu;               //This comboBox will allow the user to set the interval between every POST request,
                                      // 0.5 seconds, 1 second, 2 seconds, 4 seconds
    
   

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AufgabeAudioProcessorEditor)
};
