#pragma once

#include "PlayerStateBase.h"

class MovingPlayerState :
    public PlayerStateBase
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