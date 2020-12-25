#pragma once

#include "Game.h"

enum class ActorType {
	BACKGROUND,
	PLAYER,
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
