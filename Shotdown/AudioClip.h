#pragma once

#include <SDL.h>;
#include <iostream>
#include <string> 
using namespace std;

class AudioClip
{
public:
	AudioClip(string filename);
	~AudioClip();
	/* Actions */
	void play();
private:
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioDeviceID deviceId;
};