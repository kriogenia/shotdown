#include "Map.h"

Map::Map(Game* game) :
	game(game)
{
	tiles.clear();
}

Map::~Map()
{
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
		//space->addStaticActor(tile);
	}

}