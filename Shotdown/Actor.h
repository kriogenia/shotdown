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
	virtual void render();
	/* Destruction */
	virtual void destroy();
	/* Physics */
	cpBody* body = nullptr;
	cpShape* shape = nullptr;
	virtual void configureChipmunkSpace(cpSpace* chipSpace) {};
	bool isOverlap(Actor* actor);
	/* Position */
	Point position = { 0, 0 };
	
protected:
	/* Game instance */
	Game* game;
	/* Texture */
	SDL_Texture* texture;
	/* Properties */
	ActorType type;
	bool pendingDestruction = false;
	/* Velocity */
	float vx = 0;
	float vy = 0;
	/* Size */
	int width;
	int height;
	/* File size */
	int fileWidth;
	int fileHeight;
};
