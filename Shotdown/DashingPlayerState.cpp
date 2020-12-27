#include "DashingPlayerState.h"

DashingPlayerState::DashingPlayerState(Player* player) :
	PlayerState(player)
{
	tag = ePlayerStates::DASHING;
}

void DashingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now DASHING " << endl;
	remainingDuration = PLAYER_DASH_DURATION;
}

void DashingPlayerState::tick()
{
	// Dash out
	remainingDuration--;
	if (remainingDuration <= 0) {
		if (cpBodyGetVelocity(player->body).y > 0) {
			player->setState(ePlayerStates::FALLING);
		}
		else {
			player->setState(ePlayerStates::IDLE);
		}
	}
}

void DashingPlayerState::exit()
{
	player->dashCd = DASH_CD;
}

void DashingPlayerState::hitLeft()
{
	player->orientation = Orientation::RIGHT;
	player->setState(ePlayerStates::SLIDING);
}

void DashingPlayerState::hitRight()
{
	player->orientation = Orientation::LEFT;
	player->setState(ePlayerStates::SLIDING);
}