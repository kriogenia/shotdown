#pragma once

#include "PlayerState.h"

class MovingPlayerState :
    public PlayerState
{
public:
    MovingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void tick() override;
    /* PlayerState */
    // Control
    void move(int direction) override;
    void jump() override;

};