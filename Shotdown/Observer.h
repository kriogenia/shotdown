#pragma once

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

/* interface */
class Observer
{
public:
	Observer* getInstance();

	void notify(Notifications message, void* publisher = nullptr);
private:
	Observer* instance;

	Observer();
};