#include "Tile.h"

Tile::Tile(int tileNum, float x, float y, Game* game)
	: Actor(ActorType::TILE, "res/tiles/tileset.png", x, y, TILE_SIZE, TILE_SIZE, 384, 256, game) 
{
	this->tileNum = tileNum;
}

void Tile::render(float scrollX) {
	// Pointer to the specified portion
	int xOfTileInFile = (tileNum % TILES_PER_LINE_ON_FILE) - 1;
	int yOfTileInFile = tileNum / TILES_PER_LINE_ON_FILE;
	// Portion from source
	SDL_Rect source;
	source.x = xOfTileInFile * TILE_SIZE;
	source.y = yOfTileInFile * TILE_SIZE;
	source.w = TILE_SIZE;
	source.h = TILE_SIZE;
	// Destination to draw
	SDL_Rect destination;
	destination.x = position.x - TILE_SIZE / 2 - scrollX;
	destination.y = position.y - TILE_SIZE / 2;
	destination.w = TILE_SIZE;
	destination.h = TILE_SIZE;
	// Render invocation
	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}

void Tile::configureChipmunkSpace(cpSpace* chipSpace) {
	// Create the body
	body = cpBodyNewStatic(); 
	cpBodySetPosition(body, cpv(position.x, position.y));
	// Create the shape
	shape = cpBoxShapeNew(body, width, height, 0.0);
	cpShapeSetElasticity(shape, 0);
	cpShapeSetFriction(shape, TILE_SHAPE_FRICTION);
	cpSpaceAddShape(chipSpace, shape);
	// Reference to the Actor into the Shape
	cpShapeSetUserData(shape, cpDataPointer(this));
}
