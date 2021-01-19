#include "DoubleJumpingPlayerState.h"

DoubleJumpingPlayerState::DoubleJumpingPlayerState(Player* actor) :
	PlayerStateBase(actor)
{
	tag = ePlayerStates::DOUBLE_JUMPING;
	string animFilename = player->tag == PlayerTag::P1 ? "res/players/p1.png" : "res/players/p2.png";
	animation = new Animation(animFilename, 120, 240, 5, 8, 4, static_cast<int>(tag), false, player->game);
}

void DoubleJumpingPlayerState::enter()
{
	animation->reset();
	// cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now DOUBLE JUMPING " << endl;
	// play jump animation
}

void DoubleJumpingPlayerState::tick()
{
	PlayerStateBase::tick();
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