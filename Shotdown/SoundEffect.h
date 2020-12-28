#pragma once

#include <SDL_mixer.h>
#include <iostream>
#include <string> 
using namespace std;

class SoundEffect
{
public:
	SoundEffect(string filename);
	void play();

private:
	Mix_Chunk* mix = nullptr;
};

