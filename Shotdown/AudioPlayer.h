#pragma once

#include "AudioClip.h"
#include "BackgroundAudio.h"
#include <map>
#include <vector>

enum class AudioClips {
	DEAD,
	NO_AMMO
};

/* Singleton */
class AudioPlayer
{
public:
	static AudioPlayer* getInstance();
	~AudioPlayer();
	/* Actions */
	void start();
	void next();
	void end();
	void play(AudioClips key);

private:
	static AudioPlayer* instance;

	AudioPlayer();
	/* Background tracks */
	BackgroundAudio* currentTheme;
	BackgroundAudio* menuTheme;
	BackgroundAudio* endTheme;
	vector<BackgroundAudio*> themes;
	unsigned int index = 0;
	/* Audio clips */
	map<AudioClips, AudioClip*> clips;

};