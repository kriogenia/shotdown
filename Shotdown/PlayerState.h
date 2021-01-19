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
	DASHING,
	DYING
};

class PlayerState :
    public State
{
public:
	/* Game cycle */
	virtual void tick() {};
	virtual void render(float rotation = 0.0) {};
	/* Player control */
	virtual void move(int direction) = 0;
	virtual void jump() = 0;
	virtual void dash() = 0;
	virtual void pressTrigger() = 0;
	virtual void releaseTrigger() = 0;
	/* Events */
	virtual void impacted(PlayerTag shooter, int damage, cpVect velocity) = 0;
	virtual void recoil(int force, cpVect point) = 0;
	virtual void hitTop() {};
	virtual void hitLeft() {};
	virtual void hitRight() {};
	virtual void hitGround() {};
	/* Tag */
	ePlayerStates tag;

};

