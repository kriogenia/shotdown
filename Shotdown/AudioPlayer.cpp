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
	menuTheme = new BackgroundAudio("res/audio/themes/Ludum Dare 30 - Track 2.wav");
	endTheme = new BackgroundAudio("res/audio/themes/Ludum Dare 30 - Track 8.wav");
	themes.push_back(new BackgroundAudio("res/audio/themes/Ludum Dare 28 - Track 1.wav"));
	themes.push_back(new BackgroundAudio("res/audio/themes/Ludum Dare 28 - Track 3.wav"));
	themes.push_back(new BackgroundAudio("res/audio/themes/Ludum Dare 28 - Track 5.wav"));
	themes.push_back(new BackgroundAudio("res/audio/themes/Ludum Dare 28 - Track 8.wav"));
	themes.push_back(new BackgroundAudio("res/audio/themes/Ludum Dare 30 - Track 4.wav"));
	currentTheme = menuTheme;
	// Add audio clips
	clips.insert_or_assign(AudioClips::DASH, new SoundEffect("res/audio/clips/dash.wav"));
	clips.insert_or_assign(AudioClips::DEAD, new SoundEffect("res/audio/clips/dead.wav"));
	clips.insert_or_assign(AudioClips::GO, new SoundEffect("res/audio/clips/go.wav"));
	clips.insert_or_assign(AudioClips::IMPACT, new SoundEffect("res/audio/clips/impact.wav"));
	clips.insert_or_assign(AudioClips::NO_AMMO, new SoundEffect("res/audio/clips/no_ammo.wav"));
	clips.insert_or_assign(AudioClips::RELOAD, new SoundEffect("res/audio/clips/reload.wav"));
	clips.insert_or_assign(AudioClips::SELECT, new SoundEffect("res/audio/clips/select.mp3"));
}

AudioPlayer::~AudioPlayer()
{
	delete menuTheme;
	delete endTheme;
	themes.clear();
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
void AudioPlayer::play(AudioClips key)
{
	clips[key]->play();
}