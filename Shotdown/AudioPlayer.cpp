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
	// Add background themes
	menuTheme = new BackgroundAudio("res/audio/Ludum Dare 30 - Track 2.wav");
	endTheme = new BackgroundAudio("res/audio/Ludum Dare 30 - Track 8.wav");
	themes.push_back(new BackgroundAudio("res/audio/Ludum Dare 28 - Track 1.wav"));
	themes.push_back(new BackgroundAudio("res/audio/Ludum Dare 28 - Track 3.wav"));
	themes.push_back(new BackgroundAudio("res/audio/Ludum Dare 28 - Track 5.wav"));
	themes.push_back(new BackgroundAudio("res/audio/Ludum Dare 28 - Track 8.wav"));
	themes.push_back(new BackgroundAudio("res/audio/Ludum Dare 30 - Track 4.wav"));
	currentTheme = menuTheme;

	// clips.insert_or_assign(TRACK_BLOCKED_SHOT, new AudioClip("res/audio/blocked_shot.wav"));

}

AudioPlayer::~AudioPlayer()
{
	delete currentTheme;
	clips.clear();
}

/* Plays the starting theme, the menu theme */
void AudioPlayer::start()
{
	currentTheme->stop();
	currentTheme = menuTheme;
	currentTheme->play();
}

/* Plays the next background track */
void AudioPlayer::next()
{
	currentTheme->stop();
	currentTheme = themes[index];
	index++;
	if (index > themes.size()) {
		index = 0;
	}
	currentTheme->play();
}

/* Plays the ending theme */
void AudioPlayer::end()
{
	currentTheme->stop();
	currentTheme = endTheme;
	currentTheme->play();
}

/* Plays the specified clip */
void AudioPlayer::play(eAudioClips key)
{
	clips[key]->play();
}