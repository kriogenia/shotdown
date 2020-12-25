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
	if (player->position.y < HEIGHT)
		cout << cpBodyGetVelocity(player->body).y << endl;
	// Fall end check
	if (cpBodyGetVelocity(player->body).y < 0.01) {
		ticksGrounded++;
		if (ticksGrounded >= TICKS_TO_SWAP) {
			player->setState(ePlayerStates::IDLE);
		}
	}
	else {
		ticksGrounded = 0;
	}
}

void FallingPlayerState::jump()
{
	if (player->prevState->tag != ePlayerStates::DOUBLE_JUMPING) {
		PlayerState::jump();
		player->setState(ePlayerStates::DOUBLE_JUMPING);
	}
}

void FallingPlayerState::hitLeft()
{
	player->setState(ePlayerStates::SLIDING);
}

void FallingPlayerState::hitRight()
{
	player->setState(ePlayerStates::SLIDING);
}

void FallingPlayerState::hitGround()
{
	//player->setState(ePlayerStates::IDLE);
}