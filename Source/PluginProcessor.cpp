/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AufgabeAudioProcessor::AufgabeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::canonicalChannelSet(16), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::canonicalChannelSet(16), true)
                     #endif
                       )
#endif
{
    startTimer(1000);
}

AufgabeAudioProcessor::~AufgabeAudioProcessor()
{
}

//==============================================================================
const String AufgabeAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AufgabeAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AufgabeAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AufgabeAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AufgabeAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AufgabeAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AufgabeAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AufgabeAudioProcessor::setCurrentProgram (int index)
{
}

const String AufgabeAudioProcessor::getProgramName (int index)
{
    return {};
}

void AufgabeAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AufgabeAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void AufgabeAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AufgabeAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AufgabeAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

   
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        getRMSValuesForAllChannels(buffer);
        
    }
    
}

//==============================================================================
bool AufgabeAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AufgabeAudioProcessor::createEditor()
{
    return new AufgabeAudioProcessorEditor (*this);
}

//==============================================================================
void AufgabeAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AufgabeAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AufgabeAudioProcessor();
}

//===============================================================================
//Get for every channel

float AufgabeAudioProcessor::getCh1RMS()
{
    return ch1RMS;
}

float AufgabeAudioProcessor::getCh2RMS()
{
    return ch2RMS;
}

float AufgabeAudioProcessor::getCh3RMS()
{
    return ch3RMS;
}

float AufgabeAudioProcessor::getCh4RMS()
{
    return ch4RMS;
}

float AufgabeAudioProcessor::getCh5RMS()
{
    return ch5RMS;
}

float AufgabeAudioProcessor::getCh6RMS()
{
    return ch6RMS;
}

float AufgabeAudioProcessor::getCh7RMS()
{
    return ch7RMS;
}

float AufgabeAudioProcessor::getCh8RMS()
{
    return ch8RMS;
}

float AufgabeAudioProcessor::getCh9RMS()
{
    return ch9RMS;
}


float AufgabeAudioProcessor::getCh10RMS()
{
    return ch10RMS;
}

float AufgabeAudioProcessor::getCh11RMS()
{
    return ch11RMS;
}

float AufgabeAudioProcessor::getCh12RMS()
{
    return ch12RMS;
}

float AufgabeAudioProcessor::getCh13RMS()
{
    return ch13RMS;
}

float AufgabeAudioProcessor::getCh14RMS()
{
    return ch14RMS;
}

float AufgabeAudioProcessor::getCh15RMS()
{
    return ch15RMS;
}

float AufgabeAudioProcessor::getCh16RMS()
{
    return ch16RMS;
}

 void AufgabeAudioProcessor::getRMSValuesForAllChannels(AudioBuffer<float>& buffer)
{
    ch1RMS = buffer.getRMSLevel(0, 0, buffer.getNumSamples());
    ch2RMS = buffer.getRMSLevel(1, 0, buffer.getNumSamples());
    ch3RMS = buffer.getRMSLevel(2, 0, buffer.getNumSamples());
    
    ch4RMS = buffer.getRMSLevel(3, 0, buffer.getNumSamples());
    ch5RMS = buffer.getRMSLevel(4, 0, buffer.getNumSamples());
    ch6RMS = buffer.getRMSLevel(5, 0, buffer.getNumSamples());
    ch7RMS = buffer.getRMSLevel(6, 0, buffer.getNumSamples());
    ch8RMS = buffer.getRMSLevel(7, 0, buffer.getNumSamples());
   
    ch9RMS = buffer.getRMSLevel(8, 0, buffer.getNumSamples());
    ch10RMS = buffer.getRMSLevel(9, 0, buffer.getNumSamples());
    ch11RMS = buffer.getRMSLevel(10, 0, buffer.getNumSamples());
    ch12RMS = buffer.getRMSLevel(11, 0, buffer.getNumSamples());
    ch13RMS = buffer.getRMSLevel(12, 0, buffer.getNumSamples());
    ch14RMS = buffer.getRMSLevel(13, 0, buffer.getNumSamples());
    ch15RMS = buffer.getRMSLevel(14, 0, buffer.getNumSamples());
    ch16RMS = buffer.getRMSLevel(15, 0, buffer.getNumSamples());
     
     
}
//===============================================================================

void AufgabeAudioProcessor::timerCallback()
{
    POST();
}

//===============================================================================

void AufgabeAudioProcessor::POST()
{
    if (!url.isEmpty())
    {
    StringPairArray responseHeaders;
    int statusCode = 0;
    
    //DBG ( "POST Method");
    
        String s = jsonMessage();
    
    if(!s.isEmpty())
    {
    url = url.withPOSTData(s);
        //DBG("Post data sended:");
        //DBG(s);
    }
    
    std::unique_ptr<InputStream> stream (url.createInputStream (true, nullptr, nullptr, {"Content-Type: application/json"}, 10000, &responseHeaders, &statusCode, 5, "POST"));
    
    String response  = stream->readEntireStreamAsString().toStdString();
    String head = responseHeaders.getDescription().toStdString();
    if (stream.get() != nullptr)
    {
        std::cout<<"status code: "<<statusCode<<std::endl;
        std::cout<<head<<std::endl;
        std::cout<<response<<std::endl;
        //DBG("Stream is not empty");
    }
        
    }
    
}


String AufgabeAudioProcessor::jsonMessage()
{
    DynamicObject* obj = new DynamicObject();
    obj->setProperty("Message Empty", "All Channels Disabled");
    
    if (sendCh1 ==true) {
        obj->setProperty("Ch1",Decibels::gainToDecibels(ch1RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh2 == true) {
        obj->setProperty("Ch2",Decibels::gainToDecibels(ch2RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh3 == true) {
        obj->setProperty("Ch3",Decibels::gainToDecibels(ch3RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh4 ==true) {
        obj->setProperty("Ch4",Decibels::gainToDecibels(ch4RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh5 == true) {
        obj->setProperty("Ch5",Decibels::gainToDecibels(ch5RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh6 == true) {
        obj->setProperty("Ch6",Decibels::gainToDecibels(ch6RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh7 ==true) {
        obj->setProperty("Ch7",Decibels::gainToDecibels(ch7RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh8 == true) {
        obj->setProperty("Ch8",Decibels::gainToDecibels(ch8RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh9 == true) {
        obj->setProperty("Ch9",Decibels::gainToDecibels(ch9RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh10 ==true) {
        obj->setProperty("Ch10",Decibels::gainToDecibels(ch10RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh11 == true) {
        obj->setProperty("Ch11",Decibels::gainToDecibels(ch11RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh12 == true) {
        obj->setProperty("Ch12",Decibels::gainToDecibels(ch12RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh13 ==true) {
        obj->setProperty("Ch13",Decibels::gainToDecibels(ch13RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh14 == true) {
        obj->setProperty("Ch14",Decibels::gainToDecibels(ch14RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh15 == true) {
        obj->setProperty("Ch15",Decibels::gainToDecibels(ch15RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        }
    }
    if (sendCh16 == true) {
        obj->setProperty("Ch16",Decibels::gainToDecibels(ch16RMS));
        if (obj->hasProperty("Message Empty")) {
            obj->removeProperty("Message Empty");
        } 
    }
    
    var json (obj);
    
    return JSON::toString(json);
    
}

//===============================================================================
void AufgabeAudioProcessor::sendChanger(String s)
{
    if (s == "Ch1")
    {
        if (sendCh1 == false)
        {
            sendCh1 = true;
        }
        else
        {
            sendCh1 = false;
        }
        
    }
    else if (s == "Ch2")
    {
        if (sendCh2 == false)
        {
            sendCh2 = true;
        }
        else
        {
            sendCh2 = false;
        }
        
    }
    else if (s == "Ch3")
    {
        if (sendCh3 == false)
        {
            sendCh3 = true;
        }
        else
        {
            sendCh3 = false;
        }
        
    }
    else if (s == "Ch4")
    {
        if (sendCh4 == false)
        {
            sendCh4 = true;
        }
        else
        {
            sendCh4 = false;
        }
        
    }
    else if (s == "Ch5")
    {
        if (sendCh5 == false)
        {
            sendCh5 = true;
        }
        else
        {
            sendCh5 = false;
        }
        
    }else if (s == "Ch6")
    {
        if (sendCh6 == false)
        {
            sendCh6 = true;
        }
        else
        {
            sendCh6 = false;
        }
        
    }
    else if (s == "Ch7")
    {
        if (sendCh7 == false)
        {
            sendCh7 = true;
        }
        else
        {
            sendCh7 = false;
        }
        
    }
    else if (s == "Ch8")
    {
        if (sendCh8 == false)
        {
            sendCh8 = true;
        }
        else
        {
            sendCh8 = false;
        }
        
    }
    else if (s == "Ch9")
    {
        if (sendCh9 == false)
        {
            sendCh9 = true;
        }
        else
        {
            sendCh9 = false;
        }
        
    }
    else if (s == "Ch10")
    {
        if (sendCh10 == false)
        {
            sendCh10 = true;
        }
        else
        {
            sendCh10 = false;
        }
        
    }
    else if (s == "Ch11")
    {
        if (sendCh11 == false)
        {
            sendCh11 = true;
        }
        else
        {
            sendCh11 = false;
        }
        
    }
    else if (s == "Ch12")
    {
        if (sendCh12 == false)
        {
            sendCh12 = true;
        }
        else
        {
            sendCh12 = false;
        }
        
    }
    else if (s == "Ch13")
    {
        if (sendCh13 == false)
        {
            sendCh13 = true;
        }
        else
        {
            sendCh13 = false;
        }
        
    }else if (s == "Ch14")
    {
        if (sendCh14 == false)
        {
            sendCh14 = true;
        }
        else
        {
            sendCh14 = false;
        }
        
    }
    else if (s == "Ch15")
    {
        if (sendCh15 == false)
        {
            sendCh15 = true;
        }
        else
        {
            sendCh15 = false;
        }
        
    }
    else if (s == "Ch16")
    {
        if (sendCh16 == false)
        {
            sendCh16 = true;
        }
        else
        {
            sendCh16 = false;
        }
        
    }
    
}










