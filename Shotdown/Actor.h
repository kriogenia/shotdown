#pragma once

#include "Game.h"

enum class ActorType {
	BACKGROUND,
	TILE
};

class Actor
{
public:
	Actor(ActorType type, string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game);
	Actor(ActorType type, string filename, float x, float y, int width, int height, Game* game);
	~Actor();
	/* Game cycle */
	virtual void render(float scrollX = 0);
	/* Destruction */
	virtual void destroy();
	
protected:
	/* Game instance */
	Game* game;
	/* Texture */
	SDL_Texture* texture;
	/* Properties */
	ActorType type;
	bool pendingDestruction = false;
	/* Position */
	Point position = { 0, 0 };
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
