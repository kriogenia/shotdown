#pragma once

#include "PlayerState.h"

class IdlePlayerState :
    public PlayerState
{
public:
    IdlePlayerState(Player* actor);
    /* State */
    void enter() override;
    void update() override;
    /* PlayerState */
    // Control
    void move(int direction) override;
    void jump() override;

};