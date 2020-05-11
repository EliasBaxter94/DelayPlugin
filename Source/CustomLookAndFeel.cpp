/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 5 Mar 2020 7:59:08pm
    Author:  Elias Baxter

  ==============================================================================
*/

#include "CustomLookAndFeel.h"


CustomisedLookAndFeel::CustomisedLookAndFeel()
{
    setColour(Slider::thumbColourId, sliderColour);
    setColour(Slider::rotarySliderOutlineColourId, Colours::mediumpurple);
    setColour(Slider::rotarySliderFillColourId, Colours::black);
}

int CustomisedLookAndFeel::getSliderThumbRadius(Slider &slider)
{
    return newThumbRadius;
}

void CustomisedLookAndFeel::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
        const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    const float radius = jmin (width / 2, height / 2) - 2.0f;
    const float centreX = x + width * 0.5f;
    const float centreY = y + height * 0.5f;
    const float rx = centreX - radius;
    const float ry = centreY - radius;
    const float rw = radius * 2.0f;
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();

    if (radius > 12.0f)
    {
        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha (isMouseOver ? 1.0f : 0.7f));
        else
            g.setColour (Colour (0x80808080));

        const float thickness = 0.75f;

        {
            Path filledArc;
            filledArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, angle, thickness);

            g.fillPath (filledArc);
        }

        if (thickness > 0)
        {
            const float innerRadius = radius * 0.5f;
            Path p;


            static const unsigned char pathData[] = { 110,109,133,139,229,67,164,176,92,67,98,133,139,229,67,221,68,73,67,153,153,221,67,72,97,57,67,215,227,211,67,72,97,57,67,98,244,45,202,67,72,97,57,67,41,60,194,67,31,69,73,67,41,60,194,67,164,176,92,67,108,41,60,194,67,80,141,48,67,98,41,60,194,67,137,
                    33,29,67,61,74,186,67,244,61,13,67,123,148,176,67,244,61,13,67,98,152,222,166,67,244,61,13,67,205,236,158,67,203,33,29,67,205,236,158,67,80,141,48,67,108,205,236,158,67,80,141,48,67,108,205,236,158,67,80,141,48,67,108,205,236,158,67,113,61,13,66,98,205,
                    236,158,67,90,57,126,65,225,250,150,67,0,0,0,0,31,69,141,67,0,0,0,0,108,31,69,141,67,0,0,0,0,98,60,143,131,67,0,0,0,0,226,58,119,67,113,61,126,65,226,58,119,67,113,61,13,66,108,226,58,119,67,14,141,48,67,108,226,58,119,67,96,229,30,67,98,226,58,119,67,
                    153,121,11,67,11,87,103,67,8,44,247,66,134,235,83,67,8,44,247,66,108,134,235,83,67,8,44,247,66,98,191,127,64,67,8,44,247,66,42,156,48,67,219,121,11,67,42,156,48,67,96,229,30,67,108,42,156,48,67,219,105,132,67,108,83,184,32,67,53,254,112,67,98,165,16,
                    15,67,147,24,82,67,80,98,201,66,213,248,67,67,86,227,144,66,164,144,78,67,98,94,15,136,66,176,114,79,67,152,195,130,66,148,24,82,67,112,103,119,66,172,220,83,67,98,52,8,77,66,139,236,90,67,145,23,84,66,119,222,98,67,145,23,84,66,90,132,101,67,98,145,
                    23,84,66,61,42,104,67,22,174,206,66,184,174,141,67,148,120,4,67,88,185,167,67,98,148,120,4,67,88,185,167,67,46,18,30,67,246,232,188,67,224,111,57,67,213,8,203,67,108,224,111,57,67,168,70,216,67,98,224,111,57,67,82,88,238,67,60,191,92,67,0,0,0,68,72,113,
                    132,67,0,0,0,68,108,156,148,176,67,0,0,0,68,98,101,203,193,67,0,0,0,68,19,115,211,67,59,111,241,67,8,108,215,67,121,169,224,67,98,20,78,216,67,131,176,220,67,12,18,218,67,150,243,214,67,239,183,220,67,172,220,211,67,98,229,176,224,67,176,114,207,67,198,
                    139,229,67,219,105,196,67,198,139,229,67,43,247,180,67,108,198,139,229,67,164,176,92,67,99,101,0,0};


            Path svgPath;
            svgPath.loadPathFromData (pathData, sizeof (pathData));

            // Fit svgpath to inner dimensions of outlineArc
            svgPath.scaleToFit(-innerRadius, -innerRadius, innerRadius * 2.0f, innerRadius * 2.0f, true);

            p.addEllipse(-innerRadius, -innerRadius, innerRadius * 2.0f, innerRadius * 2.0f);
            g.fillPath (svgPath, AffineTransform::rotation (angle).translated (centreX, centreY));
        }

        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderOutlineColourId));
        else
            g.setColour (Colour (0x80808080));

        Path outlineArc;
        outlineArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, thickness);

        outlineArc.closeSubPath();

        g.strokePath (outlineArc, PathStrokeType (slider.isEnabled() ? (isMouseOver ? 2.0f : 1.2f) : 0.3f));
    }

    else
    {
        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha
                    (isMouseOver ? 1.0f : 0.7f));
        else
            g.setColour (Colour (0x80808080));

        Path p;

        g.fillPath (p, AffineTransform::rotation (angle).translated (centreX, centreY));
    }
}

