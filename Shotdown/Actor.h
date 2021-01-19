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
	/* Interaction */
	bool isOverlap(Actor* actor);
	bool containsPoint(Point point);
	/* Properties */
	ActorType type;
	Point position = { 0, 0 };
	bool pendingDestruction = false;
	/* Game instance */
	Game* game;
	
protected:
	/* Texture */
	SDL_Texture* texture;
	/* Size */
	int width;
	int height;
	/* File size */
	int fileWidth;
	int fileHeight;
};
