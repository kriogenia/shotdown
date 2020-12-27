#include "Map.h"

Map::Map(Game* game) :
	game(game)
{
	engine = ChipmunkHelper::getInstance();
	physicTiles.clear();
	tiles.clear();
}

Map::~Map()
{
	physicTiles.clear();
	tiles.clear();
}

void Map::render()
{
	for (auto const& tile : tiles) {
		tile->render();
	}
}

/* Creates a specified tile */
void Map::loadTMXTile(int tileNum, float x, float y, bool physic) {
	Tile* tile = new Tile(tileNum, x, y, game);
	tiles.push_back(tile);
	// Statics
	if (physic) {
		physicTiles.push_back(tile);
	}
}

/* Adds the physic tiles to the space */
void Map::addToSpace()
{
	for (auto const& tile : physicTiles) {
		engine->addActor(tile);
	}
}