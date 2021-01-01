#include "ReloadBar.h"

ReloadBar::ReloadBar(Player* player, Game* game) :
	Actor(ActorType::HUD, "res/hud/reload-bar.png", 0, 0, 48, 12, game)
{
	this->player = player;
	this->arrow = new Actor(ActorType::HUD, "res/hud/reload-arrow.png", 0, 0, 6, 12, game);
}

void ReloadBar::tick()
{
	if (player->weapon != nullptr) {
		this->position = { player->position.x, player->position.y - RELOAD_EXTRA_HEIGHT };
		float offset = static_cast<float>(player->weapon->reloadTimeLeft) / player->weapon->reloadTime;
		offset = (width - RELOAD_EXTREME_WIDTH) - (offset * (width - RELOAD_EXTREME_WIDTH)) - width / 2;
		arrow->position = { player->position.x + offset, player->position.y - RELOAD_EXTRA_HEIGHT };
	}
}

void ReloadBar::render(float rotation)
{
	Actor::render();
	arrow->render();
}