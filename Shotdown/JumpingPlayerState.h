#pragma once

#include "PlayerStateBase.h"

constexpr auto DOUBLE_JUMP_CAP = 100;

class JumpingPlayerState :
    public PlayerStateBase
{
public:
    JumpingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void tick() override;
    /* Player control */
    // Control
    void jump() override;
    // Events
    void hitLeft() override;
    void hitRight() override;
    /* Extra */
    bool doubleJump = true;

};
