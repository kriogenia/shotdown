#include "Actor.h"

Actor::Actor(ActorType type, string filename, float x, float y, 
	int width, int height, int fileWidth, int fileHeight, Game* game) :
	type(type),
	game(game),
	position({ x, y }),
	width(width),
	height(height),
	fileWidth(fileWidth),
	fileHeight(fileHeight)
{
	texture = game->getTexture(filename);
}

Actor::Actor(ActorType type, string filename, float x, float y, int width, int height, Game* game) :
	type(type),
	game(game),
	position({x, y}),
	width(width),
	height(height),
	fileWidth(width),
	fileHeight(height)
{
	texture = game->getTexture(filename);
}

Actor::~Actor()
{
	SDL_DestroyTexture(texture);
}

/* Creates the renderization of the actor */
void Actor::render(float scrollX) {
	// Portion from source
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth;	// texture.width;
	source.h = fileHeight;	// texture.height;
	// Destination to draw
	SDL_Rect destination;
	destination.x = position.x - width / 2 - scrollX;
	destination.y = position.y - height / 2;
	destination.w = width;
	destination.h = height;
	// Render invocation
	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}

/* Actions to do when the actor is destroyed */
void Actor::destroy()
{
	this->pendingDestruction = true;
}
