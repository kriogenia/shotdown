#include "DyingPlayerState.h"

#include <time.h>

DyingPlayerState::DyingPlayerState(Player* player) :
	PlayerStateBase(player)
{
	this->tag = ePlayerStates::DYING;
	setAnimation(false);
	this->animation->updateFrequence = 12;
}

void DyingPlayerState::enter()
{
	printf("%s is dead\n", player->toString().c_str());
	// Starts timer
	stamp = SDL_GetTicks();
	// Release current weapon
	delete this->player->weapon;
	this->player->weapon = nullptr;
	// Start dead animation
	animation->reset();
	messager->notify(Notifications::PLAYER_DEAD, player);
}

void DyingPlayerState::tick()
{
	/* Kills player if the animation finished and time has passed */
	if (animation->tick() && SDL_GetTicks() - stamp > 3000) {
		player->pendingDestruction = true;
	}
}