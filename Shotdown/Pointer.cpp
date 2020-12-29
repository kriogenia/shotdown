#include "Pointer.h"

Pointer::Pointer(Player* player, Game* game) :
	player(player)
{
	string content = (player->tag == PlayerTag::P1) ? "P1" : "P2";
	this->text = (new Text(content, player->position.x, player->position.y, game))
		->setSize(TextSize::CAPTION);
}

void Pointer::tick()
{
	this->text->position = { this->player->position.x, this->player->position.y - TEXT_DISTANCE };
}

void Pointer::render()
{
	text->render();
	// pointer render
}