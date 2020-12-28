#include "AudioPlayer.h"

AudioPlayer* AudioPlayer::instance = 0;

AudioPlayer* AudioPlayer::getInstance()
{
	if (instance == 0)
		instance = new AudioPlayer;
	return instance;
}

AudioPlayer::AudioPlayer()
{
	currentTheme = new BackgroundAudio("res/audio/theme_01.wav");

	// clips.insert_or_assign(TRACK_BLOCKED_SHOT, new AudioClip("res/audio/blocked_shot.wav"));

}

AudioPlayer::~AudioPlayer()
{
	delete currentTheme;
	clips.clear();
}

void AudioPlayer::start()
{
	currentTheme->play();
}

/*
void AudioPlayer::swap()
{
	currentTheme->stop();
	// get next theme
	start();
}
*/

void AudioPlayer::play(eAudioClips key)
{
	clips[key]->play();
}