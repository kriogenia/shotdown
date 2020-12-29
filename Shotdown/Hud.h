#pragma once

class Hud
{
public:
	/* Game cycle */
	virtual void tick() = 0;
	virtual void render() = 0;
	/* Showdown */
	virtual void initShowdown() = 0;

};

