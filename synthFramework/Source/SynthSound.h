/*
  ==============================================================================

    SynthSound.h
    Created: 14 Jan 2018 12:53:09am
    Author:  Troy Kurniawan

  ==============================================================================
*/


// This .cpp file follows instructions from: https://juce.com/doc/classSynthesiserSound


#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
    
public:
    
    // Returns true if this sound should be played when a given midi note is pressed.
    bool appliesToNote (int /*MIDINoteNumber*/)
    {
        return true;
    }
    
    // Returns true if the sound should be triggered by midi events on a given channel.
    bool appliesToChannel (int /*MIDIChannel*/)
    {
        return true;
    }
    
};