#pragma once

#include "Game.h"
class Game;

/* interface */
class Layer {
public:
	Layer(Game* game);
	/* Game cycle */
	virtual void init() = 0;
	virtual void processControls();
	virtual void update() = 0;
	virtual void render() = 0;
	/* Input control */
	virtual void keysToControl(SDL_Event event) = 0;
	virtual void padToControl(SDL_Event event) = 0;

	Game* game;
};