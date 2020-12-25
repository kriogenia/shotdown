#include "PlayerState.h"

PlayerState::PlayerState(Player* actor) :
	State()
{
	this->player = actor;
}
