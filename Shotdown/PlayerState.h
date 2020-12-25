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
	/* Player control */
	virtual void move(int direction) = 0;

protected:
	Player* player;
};

