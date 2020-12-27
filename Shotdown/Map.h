#pragma once

#include "ChipmunkHelper.h"
#include "Game.h"
#include "Tile.h"

class Map
{
public:
	Map(Game* game);
	~Map();
	/* Game cycle */
	void render();
	/* Tile generation */
	void loadTMXTile(int tileNum, float x, float y, bool physic);
	void addToSpace();
private:
	/* Physics */
	ChipmunkHelper* engine;
	/* Tile list */
	vector<Tile*> tiles;
	vector<Tile*> physicTiles;
	/* Game instance */
	Game* game;
};

