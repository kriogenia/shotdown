#include "Background.h"

Background::Background(Game* game)
{
	back = new Parallax("res/backgrounds/skyline-a.png", 128, 240, game);
	mid = new Parallax("res/backgrounds/buildings-bg.png", 144, 124, game);
}

Background::~Background()
{
	delete back;
	delete mid;
}

void Background::render()
{
	back->render();
	mid->render();
}