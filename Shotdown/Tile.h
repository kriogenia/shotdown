#pragma once

#include "Actor.h"

constexpr auto TILE_SIZE = 16.0;
constexpr auto TILES_PER_LINE_ON_FILE = 24;
constexpr auto TILE_SHAPE_FRICTION = 0.8;

class Tile :
    public Actor
{
public:
	//Tile(string filename, float x, float y, Game* game);
	Tile(int tileNum, float x, float y, Game* game);
	/* Game cycle */
	void render(float scrollX = 0) override;
	/* Physics */
	void configureChipmunkSpace(cpSpace* chipSpace) override;
private:
	int tileNum;
};

