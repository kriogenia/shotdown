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

void DoubleJumpingPlayerState::update()
{
	// Stop ascension check
	cout << cpBodyGetVelocity(player->body).y << endl;
	if (cpBodyGetVelocity(player->body).y > 0.01) {
		player->setState(ePlayerStates::FALLING);
	}
}

void DoubleJumpingPlayerState::hitLeft()
{
	cout << "Wall slide!!!" << endl;
}

void DoubleJumpingPlayerState::hitRight()
{
	cout << "Wall slide!!!" << endl;
}