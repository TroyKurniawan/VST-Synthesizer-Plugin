# Simple-VST-Synthsizer-Plugin

**BACKGROUND**

This repo holds files that make up my first attempt at creating a VST synthesizer plugin using the JUCE framework.

"JUCE" is a C++ framework that was designed specifically for users to create their own VSTs (Virtual Studio Technology), which are software interfaces that allow for the use of software audio synthesizer, effects plugins, and recording systems.
https://juce.com/

There is a great Youtube channel called "The Audio Programmer" that creates tutorials based on JUCE. I will be following these tutorials to help get me started in creating my first simple synthesizer plugin.
https://www.youtube.com/watch?v=Kpk67-nfpR0

For the plugin, premade libraries need to be used to produce the sounds. I am using "Maximilian". which is an open-source, MIT licensed C++ audio synthesis library.
http://maximilian.strangeloop.co.uk/
https://github.com/micknoise/Maximilian

____________________________________________

**CURRENT STATUS OF THE PROJECT (1-16-17)**

The synthesizer software currently is able to produce a saw wave "plucking" sound. A lowpass filter is applied to cut away higher frequencies. ADSR (Attack, Decay, Sustain, Release) and filter settings can be adjusted within the code.

A slider has been added to the UI that can adjust the attack of the synthesizer. The attack ranges from 0.1ms to 5000ms (or 0.0001s to 5s).

Simple changes were made to UI
