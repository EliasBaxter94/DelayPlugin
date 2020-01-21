/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayPluginAudioProcessorEditor::DelayPluginAudioProcessorEditor (DelayPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.


    setSize (200, 400);

    delayTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayTimeSlider.setRange(0.0, 1000.0, 1);
    delayTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    delayTimeSlider.setPopupDisplayEnabled(true, false, this);
    delayTimeSlider.setTextValueSuffix (" Delay Time (ms)");
    delayTimeSlider.setValue(0.0);

    //TODO: Switch this to a value tree state slider connector
    //delayTimeSlider.onValueChange = [this] {setDelayTimeSlider();};

    addAndMakeVisible(&delayTimeSlider);
}

DelayPluginAudioProcessorEditor::~DelayPluginAudioProcessorEditor()
{
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
    auto width  = 100;
    auto bounds = getLocalBounds().withTop(getLocalBounds()
            .getCentreY())
            .withBottom(getHeight()*0.75)
            .withWidth(width)
            .withX(getLocalBounds().getCentreX() - (width / 2));

    delayTimeSlider.setBounds(bounds);

}

