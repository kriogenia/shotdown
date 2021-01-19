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
	virtual void tick() = 0;
	virtual void render() = 0;
	/* Input control */
	virtual void keysToControl(SDL_Event event) = 0;
	virtual void mouseToControl(SDL_Event event) = 0;
	virtual void padToControl(SDL_Event event) = 0;
	int sleepJoystick = 0;
	SDL_GameController* gamepad = SDL_GameControllerOpen(0);
	/* References */
	AudioPlayer* audio = AudioPlayer::getInstance();
	Game* game;


};

