#pragma once

#include "PlayerState.h"

class MovingPlayerState :
    public PlayerState
{
public:
    MovingPlayerState(Player* actor);
    /* State */
    void enter() override;
    /* Player control */
    void move(int direction) override;

};