#include "Broadcaster.h"

Broadcaster* Broadcaster::instance = 0;

Broadcaster* Broadcaster::getInstance()
{
	if (instance == 0) {
		instance = new Broadcaster;
	}
	return instance;
}

Broadcaster::Broadcaster()
{
	audio = AudioPlayer::getInstance();
}

void Broadcaster::notify(Notifications notification, void* publisher)
{
	switch (notification) {
	case Notifications::EMPTY_CLIP:
		audio->play(AudioClips::NO_AMMO);
		break;
	case Notifications::PLAYER_DEAD:
		audio->play(AudioClips::DEAD);
		break;
	default:
		return;
	}
}