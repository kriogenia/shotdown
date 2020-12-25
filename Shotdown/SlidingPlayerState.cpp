#include "SlidingPlayerState.h"

SlidingPlayerState::SlidingPlayerState(Player* player) :
	PlayerState(player)
{
	tag = ePlayerStates::SLIDING;
}

void SlidingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now SLIDING" << endl;
	keepsSliding = true;
	// Set sliding speed
	cpBodySetVelocity(player->body,
		cpv(cpBodyGetVelocity(player->body).x, SLIDING_SPEED));
}

void SlidingPlayerState::update()
{
	cout << cpBodyGetVelocity(player->body).y << endl;
	// Limit player velocity
	if (cpBodyGetVelocity(player->body).y > SLIDING_SPEED) {
		cpBodySetVelocity(player->body, 
			cpv(cpBodyGetVelocity(player->body).x, SLIDING_SPEED));
	}
	// Swap to falling when not wall appended
	if (!keepsSliding) {
		player->setState(ePlayerStates::FALLING);
	}
	// Swap to idle when grounded
	if (cpBodyGetVelocity(player->body).y < 1.8) {
		ticksGrounded++;
		if (ticksGrounded >= TICKS_TO_SWAP) {
			player->setState(ePlayerStates::IDLE);
		}
	}
	else {
		ticksGrounded = 0;
	}
	// Restart to no sliding to next tick
	keepsSliding = false;
}

void SlidingPlayerState::jump()
{
	cout << "Wall jump!" << endl;
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