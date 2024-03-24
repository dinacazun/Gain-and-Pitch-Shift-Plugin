/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Homework4AudioProcessorEditor::Homework4AudioProcessorEditor (Homework4AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    dGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    dGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    dGainSlider.setRange(0.0f, 1.0f, 0.01f);
    dGainSlider.setValue(0.5f);
    dGainSlider.addListener(this);
    addAndMakeVisible(dGainSlider);
    setSize (200, 300);
}

Homework4AudioProcessorEditor::~Homework4AudioProcessorEditor()
{
}

//==============================================================================
void Homework4AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
//
//    g.setColour (juce::Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
    g.fillAll(juce::Colours::black);
}

void Homework4AudioProcessorEditor::resized()
{
    dGainSlider.setBounds(getWidth()/2 - 50, getHeight()/2, 100, 150);
}

void Homework4AudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if(slider == &dGainSlider)
    {
        audioProcessor.dGain = dGainSlider.getValue();
    }
}
