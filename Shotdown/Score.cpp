#include "Score.h"

Score::Score(string tag, Game* game)
{
	float x = (tag == "P1") ? P1_TAG_X : P2_TAG_X;
	text = new Text(tag, x, SCORE_HEIGHT, game);
	stars = new Bar("res/hud/stars.png", P1_SCORE_X, SCORE_HEIGHT, 0, 16, game);
}

void Score::render(float rotation)
{
	text->render();
	stars->render();
}

void Score::addWin()
{
	stars->currentWidth += 16;
}