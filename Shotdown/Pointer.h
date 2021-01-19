#pragma once

#include "Player.h"
#include "Text.h"

constexpr auto ARROW_DISTANCE = 14;
constexpr auto TEXT_DISTANCE = 25;

class Pointer :
	public Actor
{
public:
	Pointer(Player* player, Game* game);
	/* Game cycle */
	void tick() override;
	void render(float rotation = 0.0) override;

private:
	/* References */
	Player* player = nullptr;
	/* Components */
	Actor* focus = nullptr;
	Text* text = nullptr;
};

