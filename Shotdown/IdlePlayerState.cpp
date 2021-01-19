#include "IdlePlayerState.h"

IdlePlayerState::IdlePlayerState(Player* actor) :
	PlayerStateBase(actor)
{
	tag = ePlayerStates::IDLE;
	string animFilename = player->tag == PlayerTag::P1 ? "res/players/p1.png" : "res/players/p2.png";
	animation = new Animation(animFilename, 120, 240, 5, 8, 4, static_cast<int>(tag), true, player->game);
}

void IdlePlayerState::enter()
{
	// cout << (player->tag == PlayerTag::P1 ? "P1" : "P2") << " is now IDLE " << endl;
	// play idle animation
	ticksFalling = 0;
	cpBodySetVelocity(player->body, cpv(cpBodyGetVelocity(player->body).x, 0));
}

void IdlePlayerState::tick()
{
	PlayerStateBase::tick();
	// Falling check
	if (cpBodyGetVelocity(player->body).y > 0.01) {
		ticksFalling++;
		if (ticksFalling >= TICKS_TO_SWAP) {
			player->setState(ePlayerStates::FALLING);
		}
	}
	else {
		ticksFalling = 0;
	}
}

void IdlePlayerState::move(int direction)
{
	if (direction != 0) {
		PlayerStateBase::move(direction);
		player->setState(ePlayerStates::MOVING);
	}
}

void IdlePlayerState::jump()
{
	PlayerStateBase::jump();
	player->setState(ePlayerStates::JUMPING);
}
