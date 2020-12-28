#pragma once

#include "PlayerStateBase.h"

class DoubleJumpingPlayerState :
    public PlayerStateBase
{
public:
    DoubleJumpingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void tick() override;
    /* Player control */
    // Control
    inline void jump() override {};
    // Interaction
    void hitLeft() override;
    void hitRight() override;
    /* Extra */
    bool doubleJump = true;

};

