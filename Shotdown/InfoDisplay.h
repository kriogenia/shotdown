#pragma once

#include "ScoreBar.h"
#include "Player.h"
#include "Text.h"

constexpr auto DISPLAY_HEIGHT = HEIGHT * 0.92;
constexpr auto AMMO_HEIGHT = HEIGHT * 0.95;
constexpr auto SCORE_HEIGHT = HEIGHT * 0.9;
constexpr auto TAG_HEIGHT = HEIGHT * 0.88;
/* Player 1*/
constexpr auto P1_DISPLAY_X = WIDTH * 0.1;
/* Player 2 */
constexpr auto P2_DISPLAY_X = WIDTH * 0.9;

class InfoDisplay :
    public Actor
{
public:
    InfoDisplay(Player* player, Game* game);
	/* Game cycle */
	void tick() override;
	void render(float rotation = 0.0) override;
	/* Updates */
	void updateWeapon();
	void updateWins();

private:
	/* Modules */
	Text* ammo = nullptr;
	Text* tag = nullptr;
	ScoreBar* score = nullptr;
	Actor* weaponImage = nullptr;
	/* References */
	Player* player = nullptr;

};

