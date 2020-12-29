#pragma once

#include "Player.h"
#include "Text.h"

constexpr auto ARROW_DISTANCE = 14;
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
	Player* player = nullptr;
	/* Modules */
	Text* text = nullptr;
	Actor* pointer = nullptr;
};

