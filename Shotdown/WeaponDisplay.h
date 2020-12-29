#pragma once

#include "Player.h"
#include "Text.h"

constexpr auto DISPLAY_HEIGHT = HEIGHT * 0.95;
/* Player 1*/
constexpr auto P1_IMAGE_X = WIDTH * 0.05;
constexpr auto P1_TEXT_X = WIDTH * 0.12;
constexpr auto P2_IMAGE_X = WIDTH * 0.95;
constexpr auto P2_TEXT_X = WIDTH * 0.88;

class WeaponDisplay
{
public:
	WeaponDisplay(Player* player, Game* game);
	/* Game cycle */
	void tick();
	void render();
	/* Updates */
	void update();

private:
	/* Modules */
	Actor* weaponImage = nullptr;
	Text* ammo = nullptr;
	/* References */
	Player* player = nullptr;
	Game* game = nullptr;

};

