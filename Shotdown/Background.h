#pragma once

#include "Parallax.h"

class Background
{
public:
	Background(Game* game);
	~Background();
	/* Game cycle */
	void render();
private:
	Parallax* back;
	Parallax* mid;
};

