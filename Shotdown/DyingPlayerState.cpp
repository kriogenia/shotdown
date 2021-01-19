#include "DyingPlayerState.h"

DyingPlayerState::DyingPlayerState(Player* player) :
	PlayerStateBase(player)
{
	this->tag = ePlayerStates::DYING;
	string animFilename = player->tag == PlayerTag::P1 ? "res/players/p1.png" : "res/players/p2.png";
	animation = new Animation(animFilename, 120, 240, 5, 8, 8, static_cast<int>(tag), false, player->game);
}

void DyingPlayerState::enter()
{
	printf("%s is dead\n", player->toString().c_str());
	// Release current weapon
	delete this->player->weapon;
	this->player->weapon = nullptr;
	// Start dead animation
	animation->reset();
	messager->notify(Notifications::PLAYER_DEAD, player);
}

void DyingPlayerState::tick()
{
	PlayerStateBase::tick();
	if (animation->currentFrame == animation->totalFrames) {
		this->player->pendingDestruction = true;
	}
}