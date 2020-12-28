#pragma once

#include "Actor.h"

/* interface */
class State
{
public:
	State() {};
	/* Game cycle */
	virtual void tick() {};
	/* State swap */
	virtual void enter() {};
	virtual void exit() {};

};

