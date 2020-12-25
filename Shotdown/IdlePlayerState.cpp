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

void IdlePlayerState::jump()
{
	cpBodyApplyImpulseAtLocalPoint(player->body, cpv(0, -PLAYER_JUMP_HEIGHT), cpv(0, 0));
	player->setState(ePlayerStates::JUMPING);
}
