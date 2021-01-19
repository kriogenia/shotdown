#include "DashingPlayerState.h"

DashingPlayerState::DashingPlayerState(Player* player) :
	PlayerStateBase(player)
{
	tag = ePlayerStates::DASHING;
	setAnimation(false);
}

void DashingPlayerState::enter()
{
	printf("%s dashed\n", player->toString().c_str());
	// play dash animation
	remainingDuration = PLAYER_DASH_DURATION;
	messager->notify(Notifications::DASH);
}

void DashingPlayerState::tick()
{
	PlayerStateBase::tick();
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
	animation->reset();
}

void DashingPlayerState::impacted(PlayerTag shooter, int damage, cpVect velocity)
{
	printf("%s dodge the shot", player->toString().c_str());
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