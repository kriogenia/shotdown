#include "InfoDisplay.h"

InfoDisplay::InfoDisplay(Player* player, Game* game) :
	Actor(ActorType::HUD, "res/hud/arrows.png", 0, DISPLAY_HEIGHT, 120, 47, game)
{
	this->player = player;
	position.x = (player->tag == PlayerTag::P1) ? P1_DISPLAY_X : P2_DISPLAY_X;
	ammo = new Text("-", position.x, AMMO_HEIGHT, game);
	tag = new Text((player->tag == PlayerTag::P1) ? "P1" : "P2", position.x, TAG_HEIGHT, game);
	score = new ScoreBar("res/hud/stars.png", position.x, SCORE_HEIGHT, 0, 16, game);
}

void InfoDisplay::tick()
{
	if (player->weapon != nullptr) {
		string content = to_string(player->weapon->loadedAmmo) + "/";
		content.append(to_string(player->weapon->unloadedAmmo));
		ammo->content = content.c_str();
	}
}

void InfoDisplay::render(float rotation)
{
	Actor::render();
	score->render();
	tag->render();
	if (player->weapon != nullptr) {
		ammo->render();
		if (weaponImage != nullptr) {
			weaponImage->render();
		}
	}
}

void InfoDisplay::updateWeapon()
{
	float x;
	if (player->weapon != nullptr) {
		float x = (player->tag == PlayerTag::P1) ? P1_DISPLAY_X : P2_DISPLAY_X;
		weaponImage = new Actor(ActorType::HUD, player->weapon->filename,
			x, DISPLAY_HEIGHT, WEAPON_WIDTH, WEAPON_HEIGHT, game);
	}
	else {
		weaponImage = nullptr;
	}
}

void InfoDisplay::updateWins()
{
	score->currentWidth = player->victories * 16;
}