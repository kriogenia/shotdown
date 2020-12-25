#pragma once

#include "PlayerState.h"

class DoubleJumpingPlayerState :
    public PlayerState
{
public:
    DoubleJumpingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void update() override;
    /* Player control */
    // Control
    inline void jump() override {};
    // Interaction
    void hitLeft() override;
    void hitRight() override;
    /* Extra */
    bool doubleJump = true;

};

