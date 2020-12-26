#include "Background.h"

Background::Background(Game* game)
{
	back = new Parallax("res/backgrounds/skyline-a.png", 128, 240, game);
	mid = new Parallax("res/backgrounds/buildings-bg.png", 144, 124, game);
	front = new Parallax("res/backgrounds/near-buildings-bg.png", 493, 209, game);
}

Background::~Background()
{
	delete back;
	delete mid;
	delete front;
}

void Background::render()
{
	back->render();
	mid->render();
	//front->render();
}