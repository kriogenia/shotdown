#include "Tile.h"

Tile::Tile(int tileNum, float x, float y, Game* game)
	: Actor(ActorType::TILE, "res/tiles/tileset.png", x, y, TILE_SIZE, TILE_SIZE, 384, 256, game) 
{
	this->tileNum = tileNum;
}

void Tile::render() {
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
	destination.x = static_cast<int>(position.x - TILE_SIZE / 2);
	destination.y = static_cast<int>(position.y - TILE_SIZE / 2);
	destination.w = TILE_SIZE+1;
	destination.h = TILE_SIZE+1;
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
	cpShapeSetCollisionType(shape, static_cast<int>(type));
	cpShapeSetElasticity(shape, 0);
	cpShapeSetFriction(shape, TILE_SHAPE_FRICTION);
	cpSpaceAddShape(chipSpace, shape);
	// Reference to the Actor into the Shape
	cpShapeSetUserData(shape, cpDataPointer(this));
}
