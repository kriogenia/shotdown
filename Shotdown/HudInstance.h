#pragma once

#include "Player.h"
#include "Text.h"

constexpr auto SHOW_DURATION = 5 * TARGET_FPS;	// 5s

class HudInstance :
	public Hud
{
public:
	HudInstance(Player* player1, Player* player2, Game* game);
	~HudInstance();
	/* Game cycle */
	void tick() override;
	void render() override;
	/* Showdown */
	void initShowdown() override;

private:
	/* References */
	Game* game = nullptr;
	Player* player1 = nullptr;
	Player* player2 = nullptr;
	/* Modules */
	Text* title = nullptr;
	/* Counters */
	int show = 0;
	int round = 0;

};

