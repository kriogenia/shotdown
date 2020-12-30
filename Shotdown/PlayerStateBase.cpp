#include "PlayerStateBase.h"

PlayerStateBase::PlayerStateBase(Player* actor) :
	PlayerState()
{
	this->player = actor;
}

void PlayerStateBase::move(int direction)
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

void PlayerStateBase::jump()
{
	//cpBodyApplyImpulseAtLocalPoint(player->body, cpv(0, -PLAYER_JUMP_IMPULSE), cpv(0, 0));
	cpBodySetVelocity(player->body, cpv(cpBodyGetVelocity(player->body).x, -PLAYER_JUMP));
}

void PlayerStateBase::dash()
{
	if (player->dashCd <= 0) {
		auto direction = (player->orientation == Orientation::RIGHT) ? 1.0 : -1.0;
		auto impulse = direction * PLAYER_DASH_IMPULSE;
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(impulse, 0), cpv(0, 0));
		player->setState(ePlayerStates::DASHING);
	}
}

void PlayerStateBase::pressTrigger()
{
	if (player->weapon != nullptr) {
		player->weapon->pressTrigger();
	}
}

void PlayerStateBase::releaseTrigger()
{
	if (player->weapon != nullptr) {
		player->weapon->releaseTrigger();
	}
}

void PlayerStateBase::impacted(PlayerTag shooter, int damage, cpVect velocity)
{
	if (shooter != player->tag) {
		player->hp -= damage;
		printf("%s impacted. HP: %i\n", player->toString().c_str(), player->hp);
		if (player->hp <= 0) {
			player->setState(ePlayerStates::DYING);
		}
		player->pushedBack = PLAYER_PUSH_DURATION;
		cpBodyApplyImpulseAtLocalPoint(player->body, cpvmult(velocity, 10), cpv(0, 0));
		messager->notify(Notifications::PLAYER_IMPACT);
	}
}

void PlayerStateBase::recoil(int force, cpVect point)
{
	player->pushedBack = PLAYER_PUSH_DURATION;
	int recoil = -1 * static_cast<int>(player->orientation) * force;
	cpBodyApplyImpulseAtLocalPoint(player->body, cpv(recoil, 0), point);
}

void PlayerStateBase::setOrientation(int direction)
{
	if (direction < 0) {
		player->orientation = Orientation::LEFT;
	}
	else if (direction > 0) {
		player->orientation = Orientation::RIGHT;
	}
}