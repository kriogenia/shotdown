#include "JumpingPlayerState.h"

JumpingPlayerState::JumpingPlayerState(Player* actor) :
	PlayerState(actor)
{
	tag = ePlayerStates::JUMPING;
}

void JumpingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now JUMPING " << endl;
}

void JumpingPlayerState::update()
{
	// Stop ascension check
	if (cpBodyGetVelocity(player->body).y > 0.01) {
		player->setState(ePlayerStates::FALLING);
	}
}

void JumpingPlayerState::jump()
{
	PlayerState::jump();
	player->setState(ePlayerStates::DOUBLE_JUMPING);
}

void JumpingPlayerState::hitLeft()
{
	player->orientation = PlayerOrientation::RIGHT;
	player->setState(ePlayerStates::SLIDING);
}

void JumpingPlayerState::hitRight()
{
	player->orientation = PlayerOrientation::LEFT;
	player->setState(ePlayerStates::SLIDING);
}