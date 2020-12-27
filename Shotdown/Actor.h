#pragma once

#include <chipmunk/chipmunk.h>

#include "Game.h"

class Actor
{
public:
	Actor(ActorType type, string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game);
	Actor(ActorType type, string filename, float x, float y, int width, int height, Game* game);
	~Actor();
	/* Game cycle */
	virtual void tick() {};
	virtual void render(float rotation = 0.0);
	/* Destruction */
	virtual void destroy();
	/* Physics */
	cpBody* body = nullptr;
	cpShape* shape = nullptr;
	virtual void configureChipmunkSpace(cpSpace* chipSpace) {};
	bool isOverlap(Actor* actor);
	/* Properties */
	ActorType type;
	Point position = { 0, 0 };
	bool pendingDestruction = false;
	
protected:
	/* Game instance */
	Game* game;
	/* Texture */
	SDL_Texture* texture;
	/* Size */
	int width;
	int height;
	/* File size */
	int fileWidth;
	int fileHeight;
};
