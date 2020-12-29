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
}

void Broadcaster::notify(Notifications notification, void* publisher)
{
    switch (notification) {
	case Notifications::SHOWDOWN_INIT:
		hud->initShowdown();
		audio->next();
		audio->play(AudioClips::GO);
		break;
	case Notifications::DASH:
		audio->play(AudioClips::DASH);
		break;
	case Notifications::EMPTY_CLIP:
		audio->play(AudioClips::NO_AMMO);
		break;
	case Notifications::START_RELOAD:
        audio->play(AudioClips::RELOAD);
		// hud - reload visible
		break;
	case Notifications::PLAYER_IMPACT:
		audio->play(AudioClips::IMPACT);
		// effect blood
		break;
	case Notifications::PLAYER_DEAD:
		audio->play(AudioClips::DEAD);
		break;
	default:
		return;
	}
}