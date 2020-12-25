#pragma once

#include "Actor.h"

/* interface */
class State
{
public:
	State() {};
	/* Game cycle */
	virtual void update() = 0;
	/* State swap */
	virtual void enter() {};
	virtual void exit() {};

};

