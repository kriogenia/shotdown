#pragma once

#include "Game.h"

class Animation 
{
public:
	Animation(string filename, float fileWidth, float fileHeight, int totalFrames, int totalRows, 
		int updateFrequence, int row, bool loop, Game* game);
	/* Game cycle */
	bool tick();
	void render(Point position, bool flip = false, float rotation = 0);
	/* Control */
	void reset();
	void updateFrame();
	/* Frames */
	int currentFrame = 0;
	int totalFrames = 0;
	/* Position */
	int row = 0;
	/* Update */
	int updateTime = 0;
	int updateFrequence = 0;

private:
	Game* game;
	/* Dimensions */
	int frameWidth;								// Frame width
	int frameHeight;							// Frame height
	int fileWidth;								// Sprite Sheet width
	int fileHeight;								// Sprite Sheet height
	/* Drawing */
	SDL_Texture* texture;						// Image
	SDL_Rect source;							// Rectangle view
	/* Attributes */
	bool loop = false;

};