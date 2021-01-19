#include "Pointer.h"

Pointer::Pointer(Player* player, Game* game) :
	Actor(ActorType::HUD, "res/hud/arrow.png", 0, 0, 4, 4, game)
{
	this->player = player;
	string content = (player->tag == PlayerTag::P1) ? "P1" : "P2";
	this->focus = new Actor(ActorType::HUD, "res/hud/focus-s.png", 0, 0, 24, 32, game);
	this->text = (new Text(content, 0, 0, game));
}

void Pointer::tick()
{
	this->focus->position = this->player->position;
	this->text->position = { this->player->position.x, this->player->position.y - TEXT_DISTANCE };
	this->position = { this->player->position.x, this->player->position.y - ARROW_DISTANCE };
}

void Pointer::render(float rotation)
{
	focus->render();
	Actor::render();
	text->render();
}