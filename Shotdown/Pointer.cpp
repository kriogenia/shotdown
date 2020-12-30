#include "Pointer.h"

Pointer::Pointer(Player* player, Game* game) :
	Actor(ActorType::HUD, "res/hud/arrow.png", 0, 0, 4, 4, game)
{
	this->player = player;
	string content = (player->tag == PlayerTag::P1) ? "P1" : "P2";
	this->text = (new Text(content, 0, 0, game));
}

void Pointer::tick()
{
	this->text->position = { this->player->position.x, this->player->position.y - TEXT_DISTANCE };
	this->position = { this->player->position.x, this->player->position.y - ARROW_DISTANCE };
}

void Pointer::render(float rotation)
{
	Actor::render();
	text->render();
}