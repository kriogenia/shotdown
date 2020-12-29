#pragma once

#include "AudioPlayer.h"
#include "Hud.h"
#include <string>
using namespace std;

enum class Notifications {
	GAME_START,
	GAME_END,
	SHOWDOWN_INIT,
	DASH,
	PICK_WEAPON,
	SHOT,
	EMPTY_CLIP,
	START_RELOAD,
	END_RELOAD,
	PLAYER_IMPACT,
	PLAYER_DEAD
};

class Broadcaster
{
public:
	static Broadcaster* getInstance();
	/* Extends the message */
	void notify(Notifications notification, void* publisher = nullptr);
	/* Subscribers */
	Hud* hud = nullptr;
private:
	static Broadcaster* instance;
	Broadcaster();
	/* Subscribers */
	AudioPlayer* audio = AudioPlayer::getInstance();
};