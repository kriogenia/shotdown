#pragma once

#include "State.h"

#include "Player.h"
class Player;

class PlayerState :
    public State
{
public:
    PlayerState(Player* actor);
	/* Game cycle */
	virtual void update() {};
	/* Game controls */

private:
	Player* player;
};

