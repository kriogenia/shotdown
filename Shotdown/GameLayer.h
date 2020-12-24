#pragma once

#include "Layer.h"

class GameLayer :
    public Layer
{
public:
	GameLayer(Game* game);
	~GameLayer();
	/* Game cycle */
	void init() override {};
	//void processControls() override;
	void update() override {};
	void render() override {};
	/* Input control */
	void keysToControl(SDL_Event event) override {};
	void padToControl(SDL_Event event) override {};
};

