#include "DyingPlayerState.h"

DyingPlayerState::DyingPlayerState(Player* player) :
	PlayerStateBase(player)
{
}

void DyingPlayerState::enter()
{
	printf("%s is dead\n", player->toString().c_str());
	// Release current weapon
	delete this->player->weapon;
	this->player->weapon = nullptr;
	// Start dead animation
	messager->notify(Notifications::PLAYER_DEAD, player);
}

void DyingPlayerState::tick()
{
	// tick animation
	// check if animation finished
	// raise pendingDestruction flag
}