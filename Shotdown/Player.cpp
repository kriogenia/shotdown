#include "Player.h"

Player::Player(PlayerTag tag, Game* game)
	:Actor(ActorType::PLAYER, "res/players/p1.png", 0, 0, PLAYER_SIZE, PLAYER_SIZE, game)
{
	this->tag = tag;
}

Player::~Player()
{
}

void Player::clear()
{
}