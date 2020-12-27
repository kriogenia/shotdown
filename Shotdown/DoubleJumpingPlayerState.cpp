#include "DoubleJumpingPlayerState.h"

DoubleJumpingPlayerState::DoubleJumpingPlayerState(Player* actor) :
	PlayerState(actor)
{
	tag = ePlayerStates::DOUBLE_JUMPING;
}

void DoubleJumpingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now DOUBLE JUMPING " << endl;
}

void DoubleJumpingPlayerState::tick()
{
	// Stop ascension check
	if (cpBodyGetVelocity(player->body).y > 0.01) {
		player->setState(ePlayerStates::FALLING);
	}
}

void DoubleJumpingPlayerState::hitLeft()
{
	player->orientation = Orientation::RIGHT;
	player->setState(ePlayerStates::SLIDING);
}

void DoubleJumpingPlayerState::hitRight()
{
	player->orientation = Orientation::LEFT;
	player->setState(ePlayerStates::SLIDING);
}