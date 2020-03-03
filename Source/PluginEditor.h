/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/



class DelayPluginAudioProcessorEditor  : public AudioProcessorEditor
{
public:




    DelayPluginAudioProcessorEditor (DelayPluginAudioProcessor& parent, AudioProcessorValueTreeState& vts);
    ~DelayPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    //void setDelayTimeSlider ();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DelayPluginAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    Slider                     delayTimeSlider;
    Slider                     delayDryWetSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> delayTimeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> delayTimeDryWetAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayPluginAudioProcessorEditor)
};
