#include "PlayerState.h"

PlayerState::PlayerState(Player* actor) :
	State()
{
	this->player = actor;
}

void PlayerState::move(int direction)
{
	setOrientation(direction);
	// Checks player is not being pushed
	if (player->pushedBack <= 0) {
		if (direction > 0 && cpBodyGetVelocity(player->body).x < PLAYER_SPEED) {
			cpBodySetVelocity(player->body, cpv(PLAYER_SPEED, cpBodyGetVelocity(player->body).y));
			//cpBodyApplyImpulseAtLocalPoint(player->body, cpv(PLAYER_SPEED, 0), cpv(0, 0));
		}
		if (direction < 0 && cpBodyGetVelocity(player->body).x > -PLAYER_SPEED) {
			cpBodySetVelocity(player->body, cpv(-PLAYER_SPEED, cpBodyGetVelocity(player->body).y));
			//cpBodyApplyImpulseAtLocalPoint(player->body, cpv(-PLAYER_SPEED, 0), cpv(0, 0));
		}
	}
}

void PlayerState::jump()
{
	//cpBodyApplyImpulseAtLocalPoint(player->body, cpv(0, -PLAYER_JUMP_IMPULSE), cpv(0, 0));
	cpBodySetVelocity(player->body, cpv(cpBodyGetVelocity(player->body).x, -PLAYER_JUMP));
}

void PlayerState::dash()
{
	if (player->dashCd <= 0) {
		auto direction = (player->orientation == PlayerOrientation::RIGHT) ? 1.0 : -1.0;
		auto impulse = direction * PLAYER_DASH_IMPULSE;
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(impulse, 0), cpv(0, 0));
		player->setState(ePlayerStates::DASHING);
	}
}

void PlayerState::pressTrigger()
{
	if (player->weapon != nullptr) {
		player->weapon->pressTrigger();
	}
}

void PlayerState::releaseTrigger()
{
	if (player->weapon != nullptr) {
		player->weapon->releaseTrigger();
	}
}

void PlayerState::recoil(int force)
{
	player->pushedBack = PLAYER_PUSH_DURATION;
	int recoil = (player->orientation == PlayerOrientation::LEFT ? 1 : -1) * force;
	cpBodyApplyImpulseAtLocalPoint(player->body, cpv(recoil, 0), cpv(0, 0));
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