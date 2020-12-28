#pragma once

#include "PlayerStateBase.h"

class FallingPlayerState :
    public PlayerStateBase
{
public:
    FallingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void tick() override;
    /* Player control */
    // Control
    void jump() override;
    // Interaction
    void hitLeft() override;
    void hitRight() override;
    void hitGround() override;

private:
    int ticksGrounded = 0;
};

