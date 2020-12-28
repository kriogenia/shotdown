#pragma once

#include "AudioPlayer.h"
#include <string>
using namespace std;

enum class Notifications {
	GAME_START,
	GAME_END,
	SHOWDOWN_INIT,
	SHOT,
	EMPTY_CLIP,
	START_RELOAD,
	END_RELOAD,
	PLAYER_IMPACT,
	DASH,
	PICK_WEAPON
};

class Broadcaster
{
public:
	static Broadcaster* getInstance();
	/* Extends the message */
	void notify(Notifications notification, void* publisher = nullptr);
private:
	static Broadcaster* instance;
	Broadcaster();
	/* Suscribers */
	AudioPlayer* audio;
};