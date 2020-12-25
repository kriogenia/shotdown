#include "JumpingPlayerState.h"

JumpingPlayerState::JumpingPlayerState(Player* actor) :
	PlayerState(actor)
{
	tag = ePlayerStates::JUMPING;
}

void JumpingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now JUMPING " << endl;
}

void JumpingPlayerState::update()
{
	// Stop ascension check
	cout << cpBodyGetVelocity(player->body).y << endl;
	if (cpBodyGetVelocity(player->body).y > 0.01) {
		player->setState(ePlayerStates::FALLING);
	}
}

void JumpingPlayerState::jump()
{
	if (cpBodyGetVelocity(player->body).y > -DOUBLE_JUMP_CAP) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(0, -PLAYER_DOUBLE_JUMP_HEIGHT), cpv(0, 0));
		player->setState(ePlayerStates::DOUBLE_JUMPING);
	}
}

void JumpingPlayerState::hitLeft()
{
	player->setState(ePlayerStates::SLIDING);
}

void JumpingPlayerState::hitRight()
{
	player->setState(ePlayerStates::SLIDING);
}