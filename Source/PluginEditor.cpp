/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================

//TODO: General ideas to finish this all off.
//
// 1. Add feedback: https://www.youtube.com/watch?v=tPF748enDYM
//
// 2. Layout all the components a little nicer. If we imagine we just have 3 params initially:
//    DelayTime, Wet/Dry, Feedback. See: https://www.flstudiomusic.com/2017/10/free-phatnoise-delay-vst-plugin-released-burghrecords.html
//
// 3. Add nice Elias Baxter logo/graphic and background skin to the plugin.
//
// Stretch goals
//
// 4. So we have static delay time in ms. Can we sync the delay rate to host tempo ?
//    i.e. 1/4 note delay, 1/8th not delay.
//
// 5. Can we bump this up and add some input and output level meters?
//
// 6. How far could you go with it? https://bedroomproducersblog.com/2016/09/11/hy-delay-2-review/
//    Add filters, multi-tap, distortion/saturation?
DelayPluginAudioProcessorEditor::DelayPluginAudioProcessorEditor (DelayPluginAudioProcessor& parent, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (parent), processor (parent), valueTreeState (vts)
{
    setLookAndFeel(&customisedLookAndFeel);

    knobs.add(delayTimeSlider = new Slider());
    knobs.add(delayDryWetSlider = new Slider());

    delayTimeSlider->setSliderStyle(Slider::Rotary);
    delayTimeSlider->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    delayTimeSlider->setPopupDisplayEnabled(true, false, this);
    delayTimeSlider->setTextValueSuffix (" Delay Time (ms)");

    delayDryWetSlider->setSliderStyle(Slider::Rotary);
    delayDryWetSlider->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    delayDryWetSlider->setPopupDisplayEnabled(true, false, this);
    delayDryWetSlider->setTextValueSuffix("Delay Time (Dry/Wet");

    addAndMakeVisible(delayTimeSlider);
    delayTimeAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(valueTreeState, DelayPluginAudioProcessor::DelayTimeParamID, *delayTimeSlider);

    addAndMakeVisible(delayDryWetSlider);
    delayTimeDryWetAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(valueTreeState, DelayPluginAudioProcessor::DelayTimeDryWetID, *delayDryWetSlider);

    // Make sure we call setSize at the end of our constructor to ensure all the components
    // that we use in resized() have actually been created/constructed.
    setResizable(true, true);
    setResizeLimits(300, 400, 600, 800);
    setSize(300, 400);
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

    for (auto* k : knobs)
        knobBox.items.add (FlexItem (*k).withMinWidth(75.0f).withMinHeight(75.0f));
        knobBox.performLayout(getLocalBounds().toFloat());
}


