#include "IdlePlayerState.h"

IdlePlayerState::IdlePlayerState(Player* actor) :
	PlayerState(actor)
{
	tag = ePlayerStates::IDLE;
}

void IdlePlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now IDLE " << endl;
}

void IdlePlayerState::update()
{
	// Falling check
	if (cpBodyGetVelocity(player->body).y > 0.01) {
		player->setState(ePlayerStates::FALLING);
	}
}

void IdlePlayerState::move(int direction)
{
	if (direction != 0) {
		PlayerState::move(direction);
		player->setState(ePlayerStates::MOVING);
	}
}

void IdlePlayerState::jump()
{
	PlayerState::jump();
	player->setState(ePlayerStates::JUMPING);
}
