/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayPluginAudioProcessorEditor::DelayPluginAudioProcessorEditor (DelayPluginAudioProcessor& parent, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (parent), processor (parent), valueTreeState (vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    setLookAndFeel(&customisedLookAndFeel);

    delayTimeSlider.setSliderStyle(Slider::Rotary);
    delayTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    delayTimeSlider.setPopupDisplayEnabled(true, false, this);
    delayTimeSlider.setTextValueSuffix (" Delay Time (ms)");

    delayDryWetSlider.setSliderStyle(Slider::Rotary);
    delayDryWetSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    delayDryWetSlider.setPopupDisplayEnabled(true, false, this);
    delayDryWetSlider.setTextValueSuffix("Delay Time (Dry/Wet");

    addAndMakeVisible(delayTimeSlider);
    delayTimeAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, DelayPluginAudioProcessor::DelayTimeParamID, delayTimeSlider));

    addAndMakeVisible(&delayDryWetSlider);
    delayTimeDryWetAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment( valueTreeState, DelayPluginAudioProcessor::DelayTimeDryWetID,delayDryWetSlider));
}
//==============================================================================
DelayPluginAudioProcessorEditor::~DelayPluginAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}
//==============================================================================
void DelayPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void DelayPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    FlexBox                  knobBox;
    knobBox.flexWrap       = FlexBox::Wrap::wrap;
    knobBox.justifyContent = FlexBox::JustifyContent::center;
    knobBox.alignContent   = FlexBox::AlignContent::center;
    knobBox.flexDirection  = FlexBox::Direction::column;

    knobs.add(&delayTimeSlider); // i think the way ive added these objects to the array is causing a crash on shutdown.
    knobs.add(&delayDryWetSlider);

    for (auto* k : knobs)
        knobBox.items.add (FlexItem (*k).withMinWidth(75.0f).withMinHeight(75.0f));
        knobBox.performLayout(getLocalBounds().toFloat());
}


