/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 5 Mar 2020 7:59:08pm
    Author:  Elias Baxter

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"


#pragma once


class CustomisedLookAndFeel : public LookAndFeel_V4
{
    public:
        CustomisedLookAndFeel();
        int getSliderThumbRadius(Slider &slider) override;
        void drawRotarySlider (Graphics&, int x, int y, int width, int height,
            float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle,
            Slider&) override;

    private:
        const Colour sliderColour { Colours::black };
        const int newThumbRadius  { 10 };
};