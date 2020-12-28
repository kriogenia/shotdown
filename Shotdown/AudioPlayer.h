#pragma once

#include "AudioClip.h"
#include "BackgroundAudio.h"
#include <map>
#include <vector>

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
	void next();
	void end();
	void play(eAudioClips key);

private:
	static AudioPlayer* instance;

	AudioPlayer();
	/* Background tracks */
	BackgroundAudio* currentTheme;
	BackgroundAudio* menuTheme;
	BackgroundAudio* endTheme;
	vector<BackgroundAudio*> themes;
	int index = 0;
	/* Sound effects */
	map<eAudioClips, AudioClip*> clips;

};