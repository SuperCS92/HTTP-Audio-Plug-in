/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AufgabeAudioProcessorEditor::AufgabeAudioProcessorEditor (AufgabeAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible(ch1);
    addAndMakeVisible(ch2);
    addAndMakeVisible(ch3);
    addAndMakeVisible(ch4);
    addAndMakeVisible(ch5);
    addAndMakeVisible(ch6);
    addAndMakeVisible(ch7);
    addAndMakeVisible(ch8);
    addAndMakeVisible(ch9);
    addAndMakeVisible(ch10);
    addAndMakeVisible(ch11);
    addAndMakeVisible(ch12);
    addAndMakeVisible(ch13);
    addAndMakeVisible(ch14);
    addAndMakeVisible(ch15);
    addAndMakeVisible(ch16);
    
    addAndMakeVisible (urlBox);
    urlBox.onReturnKey = [this] {
        fetchButton.triggerClick();
        DBG("Enter pressed");
    };
    urlBox.setTextToShowWhenEmpty("Introduce an URL & press Change URL", Colours::white);
    
    
    addAndMakeVisible (fetchButton);
    fetchButton.onClick = [this] { processor.url = static_cast<URL>(urlBox.getText()) ; };
    
    addAndMakeVisible(SendAllButton);
    SendAllButton.onClick = [this] (){ sendAll(); };
    
    timerMenu.addItem("0.5 Seconds", 1);
    timerMenu.addItem("1 Second", 2);
    timerMenu.addItem("2 Seconds", 3);
    timerMenu.addItem("4 Seconds", 4);
    timerMenu.setJustificationType(Justification::centred);
    timerMenu.addListener(this);
    timerMenu.setSelectedItemIndex(1);
    addAndMakeVisible (timerMenu);
    
    
    
    startTimer (1000);        //The values will be updated every second
    
    setSize (400, 350);
}

AufgabeAudioProcessorEditor::~AufgabeAudioProcessorEditor()
{
}

//==============================================================================
void AufgabeAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
   
}

void AufgabeAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    
    {
        auto topArea = area.removeFromTop (40);
        fetchButton.setBounds (topArea.removeFromRight (100).reduced (8));
        urlBox     .setBounds (topArea.reduced (8));
    }
    
    auto firstRow = area.removeFromTop(70).removeFromRight(340);
    auto secondRow = area.removeFromTop(70).removeFromRight(340);
    auto thirdRow = area.removeFromTop(70).removeFromRight(340);
    auto fourthRow = area.removeFromTop(70).removeFromRight(340);
    auto timerArea = area.removeFromTop(70).removeFromRight(340);
    
    ch1.setBounds(firstRow.removeFromLeft(70).reduced(8));
    ch2.setBounds(firstRow.removeFromLeft(70).reduced(8));
    ch3.setBounds(firstRow.removeFromLeft(70).reduced(8));
    ch4.setBounds(firstRow.removeFromLeft(70).reduced(8));
    
    SendAllButton.setBounds(firstRow.removeFromLeft(90).reduced(5));
    
    ch5.setBounds(secondRow.removeFromLeft(70).reduced(8));
    ch6.setBounds(secondRow.removeFromLeft(70).reduced(8));
    ch7.setBounds(secondRow.removeFromLeft(70).reduced(8));
    ch8.setBounds(secondRow.removeFromLeft(70).reduced(8));
    
    ch9.setBounds(thirdRow.removeFromLeft(70).reduced(8));
    ch10.setBounds(thirdRow.removeFromLeft(70).reduced(8));
    ch11.setBounds(thirdRow.removeFromLeft(70).reduced(8));
    ch12.setBounds(thirdRow.removeFromLeft(70).reduced(8));
    
    ch13.setBounds(fourthRow.removeFromLeft(70).reduced(8));
    ch14.setBounds(fourthRow.removeFromLeft(70).reduced(8));
    ch15.setBounds(fourthRow.removeFromLeft(70).reduced(8));
    ch16.setBounds(fourthRow.removeFromLeft(70).reduced(8));
    
     timerMenu.setBounds(timerArea.removeFromLeft(280).reduced(5));

}


void AufgabeAudioProcessorEditor::timerCallback()
{
    
    valueToStringForAllChannels(levelCh1, levelCh2, levelCh3, levelCh4,
                                levelCh5, levelCh6, levelCh7, levelCh8,
                                levelCh9, levelCh10, levelCh11, levelCh12,
                                levelCh13, levelCh14, levelCh15, levelCh16);
    
    updateLevelsForAllChannels (levelCh1, levelCh2, levelCh3, levelCh4,
                                levelCh5, levelCh6, levelCh7, levelCh8,
                                levelCh9, levelCh10, levelCh11, levelCh12,
                                levelCh13, levelCh14, levelCh15, levelCh16);
    
}


String AufgabeAudioProcessorEditor::valueToString(float value)
{
    auto levelInDecibels = Decibels::gainToDecibels(value);
    String level (Decibels::toString(levelInDecibels,1));
    
    return level;
}


void AufgabeAudioProcessorEditor::valueToStringForAllChannels(String& Sch1, String& Sch2, String& Sch3, String& Sch4,
                                                              String& Sch5, String& Sch6, String& Sch7, String& Sch8,
                                                              String& Sch9, String& Sch10, String& Sch11, String& Sch12,
                                                              String& Sch13, String& Sch14, String& Sch15, String& Sch16)
{
    Sch1 = valueToString(processor.getCh1RMS());
    Sch2 = valueToString(processor.getCh2RMS());
    Sch3 = valueToString(processor.getCh3RMS());
    Sch4 = valueToString(processor.getCh4RMS());
    Sch5 = valueToString(processor.getCh5RMS());
    Sch6 = valueToString(processor.getCh6RMS());
    Sch7 = valueToString(processor.getCh7RMS());
    Sch8 = valueToString(processor.getCh8RMS());
    Sch9 = valueToString(processor.getCh9RMS());
    Sch10 = valueToString(processor.getCh10RMS());
    Sch11 = valueToString(processor.getCh11RMS());
    Sch12 = valueToString(processor.getCh12RMS());
    Sch13 = valueToString(processor.getCh13RMS());
    Sch14 = valueToString(processor.getCh14RMS());
    Sch15 = valueToString(processor.getCh15RMS());
    Sch16 = valueToString(processor.getCh16RMS());
    
}

void AufgabeAudioProcessorEditor::updateLevelsForAllChannels(String& Sch1, String& Sch2, String& Sch3, String& Sch4,
                                                             String& Sch5, String& Sch6, String& Sch7, String& Sch8,
                                                             String& Sch9, String& Sch10, String& Sch11, String& Sch12,
                                                             String& Sch13, String& Sch14, String& Sch15, String& Sch16)
{
    ch1.updateLevel(Sch1);
    ch2.updateLevel(Sch2);
    ch3.updateLevel(Sch3);
    ch4.updateLevel(Sch4);
    ch5.updateLevel(Sch5);
    ch6.updateLevel(Sch6);
    ch7.updateLevel(Sch7);
    ch8.updateLevel(Sch8);
    ch9.updateLevel(Sch9);
    ch10.updateLevel(Sch10);
    ch11.updateLevel(Sch11);
    ch12.updateLevel(Sch12);
    ch13.updateLevel(Sch13);
    ch14.updateLevel(Sch14);
    ch15.updateLevel(Sch15);
    ch16.updateLevel(Sch16);
}



void AufgabeAudioProcessorEditor::comboBoxChanged(ComboBox* box)
{
    
    if (box == &timerMenu)
    {
        if (timerMenu.getSelectedId() == 1)
        {
            processor.startTimer(500);
            //DBG("500ms");
        }
        else if (timerMenu.getSelectedId() == 2)
        {
            processor.startTimer(1000);
             //DBG("1Second");
        }
        else if (timerMenu.getSelectedId() == 3)
        {
            processor.startTimer(2000);
             //DBG("2Second");
        }
        else if (timerMenu.getSelectedId() == 4)
        {
            processor.startTimer(4000);
             // DBG("4Second");
        }
        
    }
}


bool AufgabeAudioProcessorEditor::sendChannel(Channel * channel)
{
    return channel->getButtonState();
}


void AufgabeAudioProcessorEditor::sendAll()
{
    
    ch1.LedTriggerClick();
    ch2.LedTriggerClick();
    ch3.LedTriggerClick();
    ch4.LedTriggerClick();
    ch5.LedTriggerClick();
    ch6.LedTriggerClick();
    ch7.LedTriggerClick();
    ch8.LedTriggerClick();
    ch9.LedTriggerClick();
    ch10.LedTriggerClick();
    ch11.LedTriggerClick();
    ch12.LedTriggerClick();
    ch13.LedTriggerClick();
    ch14.LedTriggerClick();
    ch15.LedTriggerClick();
    ch16.LedTriggerClick();
}

















