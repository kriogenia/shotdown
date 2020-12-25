#include "JumpingPlayerState.h"

JumpingPlayerState::JumpingPlayerState(Player* actor) :
	PlayerState(actor)
{
}

void JumpingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now JUMPING " << endl;
	stopCounter = 0;
}

void JumpingPlayerState::update()
{
	if (cpBodyGetVelocity(player->body).y< 0.01 && 
		cpBodyGetVelocity(player->body).y> -0.01) {
		stopCounter++;
		if (stopCounter >= TICKS_TO_STOP) {
			player->setState(ePlayerStates::IDLE);
		}
	}
}

void JumpingPlayerState::exit()
{
	stopCounter = 0;
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