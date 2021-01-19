#include "FallingPlayerState.h"

FallingPlayerState::FallingPlayerState(Player* actor) :
	PlayerStateBase(actor)
{
	tag = ePlayerStates::FALLING;
	string animFilename = player->tag == PlayerTag::P1 ? "res/players/p1.png" : "res/players/p2.png";
	animation = new Animation(animFilename, 120, 240, 5, 8, 4, static_cast<int>(tag), true, player->game);
}

void FallingPlayerState::enter()
{
	// cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now FALLING " << endl;
	// play falling animation
	ticksGrounded = 0;
}

void FallingPlayerState::tick()
{
	PlayerStateBase::tick();
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
		PlayerStateBase::jump();
		player->setState(ePlayerStates::DOUBLE_JUMPING);
	}
}

void FallingPlayerState::hitLeft()
{
	player->orientation = Orientation::RIGHT;
	player->setState(ePlayerStates::SLIDING);
}

void FallingPlayerState::hitRight()
{
	player->orientation = Orientation::LEFT;
	player->setState(ePlayerStates::SLIDING);
}

void FallingPlayerState::hitGround()
{
	//player->setState(ePlayerStates::IDLE);
}