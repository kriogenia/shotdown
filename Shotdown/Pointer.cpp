#include "Pointer.h"

Pointer::Pointer(Player* player, Game* game) :
	player(player)
{
	string content = (player->tag == PlayerTag::P1) ? "P1" : "P2";
	this->text = (new Text(content, 0, 0, game))
		->setSize(TextSize::CAPTION);
	this->pointer = new Actor(ActorType::HUD, "res/hud/arrow.png", 0, 0, 4, 4, game);
}

void Pointer::tick()
{
	this->text->position = { this->player->position.x, this->player->position.y - TEXT_DISTANCE };
	this->pointer->position = { this->player->position.x, this->player->position.y - ARROW_DISTANCE };
}

void Pointer::render()
{
	text->render();
	pointer->render();
}