#include "JumpingPlayerState.h"

JumpingPlayerState::JumpingPlayerState(Player* actor) :
	PlayerState(actor)
{
	tag = ePlayerStates::JUMPING;
}

void JumpingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now JUMPING " << endl;
	ticksFalling = 0;
}

void JumpingPlayerState::update()
{
	// Stop ascension check
	if (cpBodyGetVelocity(player->body).y < 0.01) {
		ticksFalling++;
		if (ticksFalling >= TICKS_TO_SWAP) {
			player->setState(ePlayerStates::FALLING);
		}
	}
}

void JumpingPlayerState::move(int direction)
{
	if (direction > 0 && cpBodyGetVelocity(player->body).x < PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(PLAYER_SPEED, 0), cpv(0, 0));
	}
	if (direction < 0 && cpBodyGetVelocity(player->body).x > -PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(player->body, cpv(-PLAYER_SPEED, 0), cpv(0, 0));
	}
}

void JumpingPlayerState::jump()
{

}

void JumpingPlayerState::hitTop()
{
	player->setState(ePlayerStates::FALLING);
}

void JumpingPlayerState::hitLeft()
{
	cout << "Wall slide!!!" << endl;
}

void JumpingPlayerState::hitRight()
{
	cout << "Wall slide!!!" << endl;
}