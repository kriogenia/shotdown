#include "AudioClip.h"

AudioClip::AudioClip(string filename) {
	SDL_LoadWAV(filename.c_str(), &wavSpec, &wavBuffer, &wavLength);
	deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

AudioClip::~AudioClip() {
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
}

void AudioClip::play() {
	if (SDL_GetQueuedAudioSize(deviceId) > wavLength * 4) {
		SDL_ClearQueuedAudio(deviceId);
	}
	SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
}