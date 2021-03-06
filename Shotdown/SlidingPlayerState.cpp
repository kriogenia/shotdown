#include "SlidingPlayerState.h"

SlidingPlayerState::SlidingPlayerState(Player* player) :
	PlayerStateBase(player)
{
	tag = ePlayerStates::SLIDING;
	setAnimation(true);
}

void SlidingPlayerState::enter()
{
	// cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now SLIDING" << endl;
	// play slide animation
	keepsSliding = true;
	// Set sliding speed
	cpBodySetVelocity(player->body,
		cpv(cpBodyGetVelocity(player->body).x, SLIDING_SPEED));
}

void SlidingPlayerState::tick()
{
	PlayerStateBase::tick();
	// Limit player velocity
	cpBodySetVelocity(player->body, cpv(cpBodyGetVelocity(player->body).x, SLIDING_SPEED));
	// Swap to falling when not wall appended
	if (!keepsSliding) {
		player->setState(ePlayerStates::FALLING);
	}
	// Restart to no sliding to next tick
	keepsSliding = false;
}

void SlidingPlayerState::jump()
{
	// Wall jump, angled jump
	auto direction = (player->orientation == Orientation::RIGHT) ? 1.0 : -1.0;
	auto impulse = direction * PLAYER_WALL_JUMP_X;
	cpBodySetVelocity(player->body, cpv(impulse, -PLAYER_WALL_JUMP_Y));
	//cpBodyApplyImpulseAtLocalPoint(player->body, cpv(impulse, -PLAYER_WALL_JUMP_IMPULSE_Y),cpv(0, 0));
	player->setState(ePlayerStates::JUMPING);
}

void SlidingPlayerState::impacted(PlayerTag shooter, int damage, cpVect velocity)
{
	if (shooter != player->tag) {
		player->hp -= damage;
		printf("%s impacted. HP: %i\n", player->toString().c_str(), player->hp);
		player->pushedBack = PLAYER_PUSH_DURATION;
		cpBodyApplyImpulseAtLocalPoint(player->body, cpvmult(velocity, -10), cpv(0, 0));
		if (player->hp <= 0) {
			player->setState(ePlayerStates::DYING);
		}
		else {
			player->setState(ePlayerStates::FALLING);
		}
		messager->notify(Notifications::PLAYER_IMPACT);
	}
}

void SlidingPlayerState::hitLeft()
{
	keepsSliding = true;
}

void SlidingPlayerState::hitRight()
{
	keepsSliding = true;
}

void SlidingPlayerState::hitGround()
{
	cpBodySetPosition(player->body,
		cpv(cpBodyGetPosition(player->body).x, cpBodyGetPosition(player->body).y - 1));
}