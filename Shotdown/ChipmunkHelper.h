#pragma once

#include <chipmunk/chipmunk.h>

#include "Actor.h"

/* singleton */
class ChipmunkHelper
{
public:
	static ChipmunkHelper* getInstance();
	/* Game cycle */
	void tick();
	/* Configuration */
	void init();
	void setHandlers();
	/* Entites */
	void addActor(Actor* actor);
	void removeActor(Actor* actor);

private:
	/* Instance */
	static ChipmunkHelper* instance;
	ChipmunkHelper();
	/* Physics */
	cpSpace* chipSpace;
};

/* Extra body configuration functions */

void disableGravity(cpBody* body, cpVect gravity, cpFloat damping, cpFloat dt);

