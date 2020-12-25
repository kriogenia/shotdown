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
		if (direction > 0) {
			cpBodyApplyImpulseAtLocalPoint(player->body, cpv(PLAYER_SPEED, 0), cpv(0, 0));
		}
		if (direction < 0) {
			cpBodyApplyImpulseAtLocalPoint(player->body, cpv(-PLAYER_SPEED, 0), cpv(0, 0));
		}
		player->setState(ePlayerStates::MOVING);
	}
}

void IdlePlayerState::jump()
{
	cpBodyApplyImpulseAtLocalPoint(player->body, cpv(0, -PLAYER_JUMP_HEIGHT), cpv(0, 0));
	player->setState(ePlayerStates::JUMPING);
}
