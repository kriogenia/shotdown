#include "JumpingPlayerState.h"

JumpingPlayerState::JumpingPlayerState(Player* actor) :
	PlayerStateBase(actor)
{
	tag = ePlayerStates::JUMPING;
	string animFilename = player->tag == PlayerTag::P1 ? "res/players/p1.png" : "res/players/p2.png";
	animation = new Animation(animFilename, 120, 240, 5, 8, 4, static_cast<int>(tag), false, player->game);
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