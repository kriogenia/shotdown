#pragma once

#include "AudioClip.h"
#include "BackgroundAudio.h"
#include <map>

enum class eAudioClips {

};

/* Singleton */
class AudioPlayer
{
public:
	static AudioPlayer* getInstance();
	~AudioPlayer();
	/* Actions */
	void start();
	//void next();
	void play(eAudioClips key);

private:
	static AudioPlayer* instance;

	AudioPlayer();
	/* Background tracks */
	BackgroundAudio* currentTheme;
	//list<BackgroundAudio*> themes;
	/* Sound effects */
	map<eAudioClips, AudioClip*> clips;

};