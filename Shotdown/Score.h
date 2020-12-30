#pragma once

#include "Bar.h"
#include "Text.h"

constexpr auto SCORE_HEIGHT = HEIGHT * 0.90;
/* Player 1*/
constexpr auto P1_TAG_X = WIDTH * 0.05;
constexpr auto P1_SCORE_X = WIDTH * 0.12;
/* Player 2 */
constexpr auto P2_TAG_X = WIDTH * 0.95;
constexpr auto P2_SCORE_X = WIDTH * 0.88;

class Score
{
public:
	Score(string tag, Game* game);
	/* Game cycle */
	void render(float rotation = 0.0);
	/* Update */
	void addWin();

private:
	/* Modules */
	Text* text = nullptr;
	Bar* stars = nullptr;

};

