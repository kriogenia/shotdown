#include "BackgroundAudio.h"

BackgroundAudio::BackgroundAudio(string filename) :
	filename(filename)
{
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096); // 2 channels
	Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
}

BackgroundAudio::~BackgroundAudio() {
	stop();
	Mix_CloseAudio();
}

void BackgroundAudio::play() {
	mix = Mix_LoadMUS(filename.c_str());
	Mix_PlayMusic(mix, -1);
}

void BackgroundAudio::stop() {
	Mix_FreeMusic(mix);
}