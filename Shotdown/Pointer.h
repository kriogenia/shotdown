#pragma once

#include "Player.h"
#include "Text.h"

constexpr auto TEXT_DISTANCE = 25;

class Pointer
{
public:
	Pointer(Player* player, Game* game);
	/* Game cycle */
	void tick();
	void render();

private:
	/* References */
	Player* player;
	/* Modules */
	Text* text;
	Actor* pointer;
};

