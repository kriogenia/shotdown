#include "SoundEffect.h"

SoundEffect::SoundEffect(string filename)
{
	mix = Mix_LoadWAV(filename.c_str());
    if (mix == NULL) {
        printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

SoundEffect::~SoundEffect()
{
    Mix_FreeChunk(mix);
}

void SoundEffect::play()
{
    Mix_PlayChannel(-1, mix, 0);
}