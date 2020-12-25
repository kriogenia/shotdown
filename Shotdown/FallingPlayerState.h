#pragma once

#include "PlayerState.h"

class FallingPlayerState :
    public PlayerState
{
public:
    FallingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void update() override;
    /* Player control */
    void move(int direction) override;
    inline void jump() override {};

private:
    int ticksGrounded = 0;
};

