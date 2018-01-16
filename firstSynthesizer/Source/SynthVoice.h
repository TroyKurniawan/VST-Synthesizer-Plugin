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
#include "Maximilian.h"

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
        // Envelope's "attack" is triggered.
        env1.trigger = 1;
        
        // Sets the level of the notes being played based on the velocity of the MIDI controller.
        level = velocity;
        
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
        // Envelope "release" is triggered.
        env1.trigger = 0;
        allowTailOff = true;
        
        if(velocity == 0)
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
        // Envelope "ADSR" Settings
        env1.setAttack(100);    // Arguments are in milliseconds
        env1.setDecay(500);
        env1.setSustain(0.1);   // Choose a value from 0 to 1
        env1.setRelease(500);
        
        for (int sample=0; sample<numSamples; ++sample)
        {
            // Sets the waveform that goes to the output; oscillator currently outputs a 440hz sine wave.
            double theWave = osc1.saw(frequency) * level;
            
            // Set the sound to the envelope settings declared previously
            double theSound = env1.adsr(theWave, env1.trigger) * level;
            
            // Applies a filter to theSound
            double filteredSound = fil1.lores(theSound, 800, 0);
            
            for (int channel = 0; channel<outputBuffer.getNumChannels(); ++ channel)
            {
                outputBuffer.addSample(channel, startSample, filteredSound);
            }
            ++startSample;
        }
    }
    
    // =============================
    
private:
    double level;
    double frequency;
    
    // Uses components from maximilian.h =====
    
    // Instantiates oscillators
    maxiOsc osc1;
    
    // Instantiates envelopes
    maxiEnv env1;
    
    // Instantiates filters
    maxiFilter fil1;
    
};