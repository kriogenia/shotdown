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
		audio->next();
		audio->play(AudioClips::GO);
		hud->initShowdown();
		break;
	case Notifications::DASH:
		audio->play(AudioClips::DASH);
		break;
	case Notifications::PICK_WEAPON:
		hud->updateWeapon(publisher);
		hud->switchReload(publisher, false);
		break;
	case Notifications::EMPTY_CLIP:
		audio->play(AudioClips::NO_AMMO);
		break;
	case Notifications::START_RELOAD:
        audio->play(AudioClips::RELOAD);
		hud->switchReload(publisher, true);
		break;
	case Notifications::END_RELOAD:
		hud->switchReload(publisher, false);
		break;
	case Notifications::PLAYER_IMPACT:
		audio->play(AudioClips::IMPACT);
		// effect blood
		break;
	case Notifications::PLAYER_DEAD:
		audio->play(AudioClips::DEAD);
		hud->showWinner(publisher);
		break;
	default:
		return;
	}
}