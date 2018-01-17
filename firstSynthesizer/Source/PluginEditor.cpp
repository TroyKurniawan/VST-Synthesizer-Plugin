/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    
    
    // ATTACK
    
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);     // Arguments are in milliseconds
    attackSlider.setValue(0.1f);
    
    // This is a text box that will appear below the slider.
    // 1st Number Argument = Width | 2nd Number Argument = Height
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    
    attackSlider.addListener(this);
    addAndMakeVisible(&attackSlider);
    
    // Links the slider between the PluginEditor.cpp and the PluginProcessor.cpp.
    sliderTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
    
}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Troy's Simple VST Synthesizer Plugin!", getLocalBounds(), Justification::centredBottom, 1);
    
    // Attack Slider Box
    g.drawRect(5.0f, 5.0f, 50.0f, 160.0f);
    
    // Line Above Bottom Text
    g.drawLine(30, 280, 370, 280);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    // 3rd Argument = Width | 4th Argument = Height
    attackSlider.setBounds(10, 10, 40, 150);
}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if(slider == &attackSlider)
    {
        // Need to set value of attack time to the slider value
        processor.attackTime = attackSlider.getValue();
    }
}