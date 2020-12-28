#pragma once

#include "State.h"

constexpr auto TICKS_TO_SWAP = 3;

enum class ePlayerStates {
	IDLE,
	MOVING,
	JUMPING,
	DOUBLE_JUMPING,
	FALLING,
	SLIDING,
	DASHING
};

class PlayerState :
    public State
{
public:
	/* Game cycle */
	virtual void tick() {};
	/* Player control */
	virtual void move(int direction) = 0;
	virtual void jump() = 0;
	virtual void dash() = 0;
	virtual void pressTrigger() = 0;
	virtual void releaseTrigger() = 0;
	/* Events */
	virtual void hitTop() {};
	virtual void hitLeft() {};
	virtual void hitRight() {};
	virtual void hitGround() {};
	virtual void recoil(int force, cpVect point) = 0;
	/* Tag */
	ePlayerStates tag;

};

