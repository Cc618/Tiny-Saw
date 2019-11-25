# Tiny-Saw
A tiny synthesizer to make saws. Desktop app for linux, written in C++ with [Qt](https://www.qt.io/) and [Port Audio](http://www.portaudio.com/).

# Build

### Depedencies
* Qt 5
* Port Audio

### Make
To build this project just open the file [src/TinySaw.pro](src/TinySaw.pro) in QtCreator and build it.

If there is no output just restart Pulse Audio with
```bash
pulseaudio --kill
```

# Code Structure
The code is divided in two parts :

### Graphics :
* MainWindow : Handles window and key events

### Audio :
* **audio** : The file containing all functions to interract with audio from graphics
* **AudioHandler** : Handle audio components
* **SoundGenerator** : Manages all voices, mixers, oscillators
* **Voice** : Generates the sound from one note
* **Oscillator** : Provides sound wave's shape
* **Mixer** : Handles the volume

Here is a small diagram, legend :
* +-> Interracts with
* +-- Belongs to
```
Input (Keyboard / Midi)
+-> AudioHandler
    +-> SoundGenerator
        +-- Voices
        |   +-- Mixer
        |   +-- Oscillator
        +-> Output (Speakers / File)
```
