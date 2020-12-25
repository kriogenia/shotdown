#pragma once

#include "PlayerState.h"

constexpr auto DOUBLE_JUMP_CAP = 5;

class JumpingPlayerState :
    public PlayerState
{
public:
    JumpingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void update() override;
    /* Player control */
    // Control
    void jump() override;
    // Interaction
    void hitLeft() override;
    void hitRight() override;
    /* Extra */
    bool doubleJump = true;

};
