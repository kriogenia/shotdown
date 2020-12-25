#include "FallingPlayerState.h"

FallingPlayerState::FallingPlayerState(Player* actor) :
	PlayerState(actor)
{
	tag = ePlayerStates::FALLING;
}

void FallingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now FALLING " << endl;
	ticksGrounded = 0;
}

void FallingPlayerState::update()
{
	// Fall ended check
	if (cpBodyGetVelocity(player->body).y < 0.01) {
		ticksGrounded++;
		if (ticksGrounded >= TICKS_TO_SWAP) {
			player->setState(ePlayerStates::IDLE);
		}
	}
}

void FallingPlayerState::move(int direction)
{
	if (direction > 0 && cpBodyGetVelocity(player->body).x < PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(PLAYER_SPEED, 0), cpv(0, 0));
	}
	if (direction < 0 && cpBodyGetVelocity(player->body).x > -PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(-PLAYER_SPEED, 0), cpv(0, 0));
	}
}