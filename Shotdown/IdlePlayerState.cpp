#include "IdlePlayerState.h"

IdlePlayerState::IdlePlayerState(Player* actor) :
	PlayerState(actor)
{
}

void IdlePlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now IDLE " << endl;
}

void IdlePlayerState::move(int direction)
{
	if (direction != 0) {
		player->setState(ePlayerStates::MOVING);
		player->move(direction);
	}
}
