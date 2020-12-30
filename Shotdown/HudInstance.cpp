#include "HudInstance.h"

HudInstance::HudInstance(Player* player1, Player* player2, Game* game) :
	Hud()
{
	this->title = (new Text("", WIDTH / 2, HEIGHT * 0.1, game))
		->setSize(TextSize::TITLE);
	this->pointerPlayer1 = new Pointer(player1, game);
	this->pointerPlayer2 = new Pointer(player2, game);
	this->scorePlayer1 = new Score("P1", game);
	this->scorePlayer2 = new Score("P2", game);
	this->weaponPlayer1 = new WeaponDisplay(player1, game);
	this->weaponPlayer2 = new WeaponDisplay(player2, game);
}

HudInstance::~HudInstance()
{
	delete title;
	delete pointerPlayer1;
	delete pointerPlayer2;
	delete scorePlayer1;
	delete scorePlayer2;
	delete weaponPlayer1;
	delete weaponPlayer2;
}

void HudInstance::tick()
{
	show--;
	weaponPlayer1->tick();
	weaponPlayer2->tick();
	if (show > 0 || loser != 0) {
		pointerPlayer1->tick();
		pointerPlayer2->tick();
	}
}

void HudInstance::render()
{
	scorePlayer1->render();
	scorePlayer2->render();
	weaponPlayer1->render();
	weaponPlayer2->render();
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
}

void HudInstance::updateWeapon(void* player)
{
	PlayerTag tag = ((Player*)player)->tag;
	if (tag == PlayerTag::P1) {
		weaponPlayer1->update();
	}
	else {
		weaponPlayer2->update();
	}
}

void HudInstance::showWinner(void* loser)
{
	this->loser = static_cast<int>(((Player*)loser)->tag);
	if (this->loser == static_cast<int>(PlayerTag::P1)) {
		scorePlayer2->addWin();
	}
	else {
		scorePlayer1->addWin();
	}
}