#include "DashingPlayerState.h"

DashingPlayerState::DashingPlayerState(Player* player) :
	PlayerState(player)
{
	tag = ePlayerStates::DASHING;
}

void DashingPlayerState::enter()
{
	cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now MOVING " << endl;
}

void DashingPlayerState::update()
{
	cout << cpBodyGetVelocity(player->body).x << " " << cpBodyGetVelocity(player->body).y << endl;
}

void DashingPlayerState::hitLeft()
{
	player->orientation = PlayerOrientation::RIGHT;
	player->setState(ePlayerStates::SLIDING);
}

void DashingPlayerState::hitRight()
{
	player->orientation = PlayerOrientation::LEFT;
	player->setState(ePlayerStates::SLIDING);
}