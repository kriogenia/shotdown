#pragma once

#include "State.h"

#include "Player.h"
enum class ePlayerStates;
class Player;

constexpr auto TICKS_TO_SWAP = 3;

class PlayerState :
    public State
{
public:
    PlayerState(Player* actor);
	/* Game cycle */
	virtual void update() {};
	/* Player control */
	virtual void move(int direction) = 0;
	virtual void jump() = 0;
	/* Player interaction */
	virtual void hitTop() {};
	virtual void hitLeft() {};
	virtual void hitRight() {};
	virtual void hitGround() {};
	/* Tag */
	ePlayerStates tag;

protected:
	Player* player;
};

