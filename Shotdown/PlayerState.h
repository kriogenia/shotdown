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
	virtual void tick() {};
	/* Player control */
	virtual void move(int direction);
	virtual void jump();
	virtual void dash();
	virtual void pressTrigger();
	virtual void releaseTrigger();
	/* Events */
	virtual void hitTop() {};
	virtual void hitLeft() {};
	virtual void hitRight() {};
	virtual void hitGround() {};
	virtual void recoil(int force);
	/* Tag */
	ePlayerStates tag;

protected:
	/* Context pointer */
	Player* player;
	/* Orientation */
	void setOrientation(int direction);
};

