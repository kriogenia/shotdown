#include "JumpingPlayerState.h"

JumpingPlayerState::JumpingPlayerState(Player* actor) :
	PlayerStateBase(actor)
{
	tag = ePlayerStates::JUMPING;
	setAnimation(false);
}

void JumpingPlayerState::enter()
{
	animation->reset();
	// cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now JUMPING " << endl;
	// play jump animation
}

void JumpingPlayerState::tick()
{
	PlayerStateBase::tick();
	// Stop ascension check
	if (cpBodyGetVelocity(player->body).y > 0.01) {
		player->setState(ePlayerStates::FALLING);
	}
}

void JumpingPlayerState::jump()
{
	PlayerStateBase::jump();
	player->setState(ePlayerStates::DOUBLE_JUMPING);
}

void JumpingPlayerState::hitLeft()
{
	player->orientation = Orientation::RIGHT;
	player->setState(ePlayerStates::SLIDING);
}

void JumpingPlayerState::hitRight()
{
	player->orientation = Orientation::LEFT;
	player->setState(ePlayerStates::SLIDING);
}