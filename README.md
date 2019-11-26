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
* **audio** : The file managing the audio synthesis from a low level
* **input** : The file containing all input events triggered from graphics
* **AudioHandler** : Handles audio components
* **SoundGenerator** : Manages all voices and the oscillator
* **Oscillator** : Provides sound wave's shape
* **KeyHandler** : Gathers all voices for one key press, provides also the mixer
* **Mixer** : Handles the volume of a key handler
* **Voice** : Generates the sound for one frequency

Here is a small diagram, legend :
* +-> Interracts with
* +-- Belongs to
```
Input (Keyboard / Midi)
+-> input
+-> AudioHandler
	+-> SoundGenerator
		+-- Oscillator
		+-- KeyHandlers
			+-- Mixer
			+-- Voices
	+-> Output (Speakers / File)
```
