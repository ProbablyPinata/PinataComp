/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PinataCompAudioProcessorEditor::PinataCompAudioProcessorEditor (PinataCompAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (300, 300);
    
    // these define the parameters of our slider object
    midiVolume.setSliderStyle (juce::Slider::LinearBarVertical);
    midiVolume.setRange (0.0, 1.0, 0.001);
    midiVolume.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled (true, false, this);
    midiVolume.setTextValueSuffix (" Volume");
    midiVolume.setValue(p.gain);
 
    // this function adds the slider to the editor
    addAndMakeVisible (&midiVolume);
    
    midiVolume.addListener (this);
}

PinataCompAudioProcessorEditor::~PinataCompAudioProcessorEditor()
{
}

//==============================================================================
void PinataCompAudioProcessorEditor::paint (juce::Graphics& g)
{
    // g.setFont (juce::FontOptions (15.0f));
    //g.drawFittedText ("PinataComp", getLocalBounds(), juce::Justification::centred, 1);
    
    // fill the whole window white
    g.fillAll (juce::Colours::white);
 
    // set the current drawing colour to black
    g.setColour (juce::Colours::black);
 
    // set the font size and draw text to the screen
    g.setFont (15.0f);
 
    g.drawFittedText ("Volume Utility", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
    
    
}

void PinataCompAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // sets the position and size of the slider with arguments (x, y, width, height)
    midiVolume.setBounds (40, 30, 20, getHeight() - 60);
}

void PinataCompAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.gain = midiVolume.getValue();
}
