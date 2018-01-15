/*
  ==============================================================================

    SynthVoice.h
    Created: 14 Jan 2018 12:53:15am
    Author:  Troy Kurniawan

  ==============================================================================
*/


// This .cpp file follows instructions from: https://juce.com/doc/classSynthesiserVoice


#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice
{
    
public:
    
    // Must return true if this voice object is capable of playing the given sound.
    bool canPlaySound (SynthesiserSound* sound)
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }

    // ============================
    
    // Called to start a new note.
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        // Sets the variable "frequency" to the frequency of the note that the MIDI controller is playing.
        // getMidiNoteInHertz returns the appropriate frequency
        // https://juce.com/doc/classMidiMessage
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout << midiNoteNumber << std::endl;
    }
    
    // =============================
    
    // Called to stop a note.
    void stopNote (float velocity, bool allowTailOff)
    {
        clearCurrentNote();
    }
    
    // =============================
    
    // Called to let the voice know that the pitch wheel has been moved.
    void pitchWheelMoved (int newPitchWheelValue)
    {
        
    }
    
    // =============================
    
    // Called to let the voice know that a midi controller has been moved.
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    
    // =============================
    
    // Renders the next block of data for this voice.
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {
        
    }
    
    // =============================
    
private:
    double level;
    double frequency;
    
};