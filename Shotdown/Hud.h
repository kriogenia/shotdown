#pragma once

class Hud
{
public:
	/* Game cycle */
	virtual void tick() = 0;
	virtual void render() = 0;
	/* Updates */
	virtual void initShowdown() = 0;
	virtual void updateWeapon(void* player) = 0;

};

