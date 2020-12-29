#include "WeaponDisplay.h"

WeaponDisplay::WeaponDisplay(Player* player, Game* game) :
	player(player),
	game(game)
{
	float x = (player->tag == PlayerTag::P1) ? P1_TEXT_X : P2_TEXT_X;
	ammo = (new Text("-", x, DISPLAY_HEIGHT, game))->setSize(TextSize::CAPTION);
}

void WeaponDisplay::tick()
{
	if (player->weapon != nullptr) {
		string content = to_string(player->weapon->loadedAmmo) + "/";
		content.append(to_string(player->weapon->unloadedAmmo));
		ammo->content = content.c_str();
	}
}

void WeaponDisplay::render()
{
	if (player->weapon != nullptr) {
		ammo->render();
		if (weaponImage != nullptr) {
			weaponImage->render();
		}
	}
}

void WeaponDisplay::update()
{
	float x;
	if (player->weapon != nullptr) {
		float x = (player->tag == PlayerTag::P1) ? P1_IMAGE_X : P2_IMAGE_X;
		weaponImage = new Actor(ActorType::HUD, player->weapon->filename, 
			x, DISPLAY_HEIGHT, 30, 8, game);
	}
	else {
		weaponImage = nullptr;
	}
}