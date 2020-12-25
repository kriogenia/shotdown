#pragma once

#include "PlayerState.h"

class IdlePlayerState :
    public PlayerState
{
public:
    IdlePlayerState(Player* actor);

};