#pragma once

#include "PlayerState.h"

class DashingPlayerState :
    public PlayerState
{
public:
    DashingPlayerState(Player* player);
    /* State */
    void enter() override;
    void update() override;
    /* Player state */
    // Controls
    inline void move(int direction) override {};
    inline void jump() override {};
    // Events
    void hitLeft() override;
    void hitRight() override;

};
