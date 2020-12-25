#pragma once

#include "Parallax.h"

class Background
{
public:
	Background(Game* game);
	/* Game cycle */
	void render();
private:
	Parallax* back;
	Parallax* mid;
	Parallax* front;
};

