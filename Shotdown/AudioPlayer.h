#pragma once

#include "BackgroundAudio.h"
#include "SoundEffect.h"
#include <map>
#include <vector>

enum class AudioClips {
	DASH,
	DEAD,
	GO,
	IMPACT,
	NO_AMMO,
	PRESS,
	RELOAD,
	SCORE,
	SELECT,
	WINNER
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
	map<AudioClips, SoundEffect*> clips;

};