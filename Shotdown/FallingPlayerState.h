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
    // Control
    void move(int direction) override;
    void jump() override;
    // Interaction
    void hitLeft() override;
    void hitRight() override;
    void hitGround() override;

private:
    int ticksGrounded = 0;
};

