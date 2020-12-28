#include "MovingPlayerState.h"

MovingPlayerState::MovingPlayerState(Player* actor) :
	PlayerStateBase(actor)
{
	tag = ePlayerStates::MOVING;
}

void MovingPlayerState::enter()
{
	//cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now MOVING " << endl;
	// play moving animation
}

void MovingPlayerState::tick()
{
	// Falling check
	if (cpBodyGetVelocity(player->body).y > 0.01) {
		player->setState(ePlayerStates::FALLING);
	}
}

void MovingPlayerState::move(int direction)
{
	if (direction == 0) {
		player->setState(ePlayerStates::IDLE);
	}
	PlayerStateBase::move(direction);
}

void MovingPlayerState::jump()
{
	PlayerStateBase::jump();
	player->setState(ePlayerStates::JUMPING);
}