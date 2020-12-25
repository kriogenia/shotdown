#pragma once

#include "Game.h"
#include "Tile.h"

class Map
{
public:
	Map(cpSpace* chipSpace, Game* game);
	~Map();
	/* Game cycle */
	void render();
	/* Tile generation */
	void loadTMXTile(int tileNum, float x, float y, bool physic);
private:
	/* Physics */
	cpSpace* chipSpace;
	/* Tile list */
	vector<Tile*> tiles;
	/* Game instance */
	Game* game;
};

