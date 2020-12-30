#include "HudInstance.h"

HudInstance::HudInstance(Player* player1, Player* player2, Game* game) :
	Hud()
{
	this->title = (new Text("", WIDTH / 2, HEIGHT * 0.1, game))
		->setSize(TextSize::TITLE);
	this->pointerPlayer1 = new Pointer(player1, game);
	this->pointerPlayer2 = new Pointer(player2, game);
	this->infoPlayer1 = new InfoDisplay(player1, game);
	this->infoPlayer2 = new InfoDisplay(player2, game);
}

HudInstance::~HudInstance()
{
	delete title;
	delete pointerPlayer1;
	delete pointerPlayer2;
	delete infoPlayer1;
	delete infoPlayer2;
}

void HudInstance::tick()
{
	show--;
	infoPlayer1->tick();
	infoPlayer2->tick();
	if (show > 0 || loser != 0) {
		pointerPlayer1->tick();
		pointerPlayer2->tick();
	}
}

void HudInstance::render()
{
	infoPlayer1->render();
	infoPlayer2->render();
	if (show > 0) {
		pointerPlayer1->render();
		pointerPlayer2->render();
		title->render();
	}
	// Shows pointer at winning showdown
	if (loser != 0) {
		if (loser == static_cast<int>(PlayerTag::P1)) {
			pointerPlayer2->render();
		}
		else {
			pointerPlayer1->render();
		}
	}
}

void HudInstance::initShowdown()
{
	show = SHOW_DURATION;
	title->content = "Round " + to_string(++round);
	loser = 0;
	infoPlayer1->updateWins();
	infoPlayer2->updateWins();
}

void HudInstance::updateWeapon(void* player)
{
	PlayerTag tag = ((Player*)player)->tag;
	if (tag == PlayerTag::P1) {
		infoPlayer1->updateWeapon();
	}
	else {
		infoPlayer2->updateWeapon();
	}
}

void HudInstance::showWinner(void* loser)
{
	this->loser = static_cast<int>(((Player*)loser)->tag);
}