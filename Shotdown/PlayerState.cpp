#include "PlayerState.h"

PlayerState::PlayerState(Player* actor) :
	State()
{
	this->player = actor;
}

void PlayerState::move(int direction)
{
	setOrientation(direction);
	if (direction > 0 && cpBodyGetVelocity(player->body).x < PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(PLAYER_SPEED, 0), cpv(0, 0));
	}
	if (direction < 0 && cpBodyGetVelocity(player->body).x > -PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(-PLAYER_SPEED, 0), cpv(0, 0));
	}
}

void PlayerState::jump()
{
	cpBodyApplyImpulseAtLocalPoint(player->body, cpv(0, -PLAYER_JUMP_HEIGHT), cpv(0, 0));
}

void PlayerState::setOrientation(int direction)
{
	if (direction < 0) {
		player->orientation = PlayerOrientation::LEFT;
	}
	else if (direction > 0) {
		player->orientation = PlayerOrientation::RIGHT;
	}
}