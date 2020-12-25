#include "MovingPlayerState.h"

MovingPlayerState::MovingPlayerState(Player* actor) :
	PlayerState(actor)
{
	tag = ePlayerStates::MOVING;
}

void MovingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now MOVING " << endl;
}

void MovingPlayerState::update()
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
	if (direction > 0 && cpBodyGetVelocity(player->body).x < PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(PLAYER_SPEED, 0), cpv(0, 0));
	}
	if (direction < 0 && cpBodyGetVelocity(player->body).x > -PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(-PLAYER_SPEED, 0), cpv(0, 0));
	}
}

void MovingPlayerState::jump()
{
	cpBodyApplyImpulseAtLocalPoint(player->body, cpv(0, -PLAYER_JUMP_HEIGHT), cpv(0, 0));
	player->setState(ePlayerStates::JUMPING);
}