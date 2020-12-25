#pragma once

#include "PlayerState.h"

class MovingPlayerState :
    public PlayerState
{
public:
    MovingPlayerState(Player* actor);

};