#include "HudInstance.h"

HudInstance::HudInstance(Player* player1, Player* player2, Game* game) :
	Hud()
{
	this->player1 = player1;
	this->player2 = player2;
	this->title = new Text("", WIDTH / 2, HEIGHT * 0.1, true, game);
}

HudInstance::~HudInstance()
{
	delete title;
}

void HudInstance::tick()
{
	show--;
}

void HudInstance::render()
{
	if (show > 0) {
		title->render();
	}
}

void HudInstance::initShowdown()
{
	show = SHOW_DURATION;
	title->content = "Round " + to_string(++round);
}