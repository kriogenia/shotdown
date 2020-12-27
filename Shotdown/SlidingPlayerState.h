#pragma once

#include "PlayerState.h"

class SlidingPlayerState :
    public PlayerState
{
public:
    SlidingPlayerState(Player* player);
    /* State */
    void enter() override;
    void tick() override;
    /* PlayerState */
    // Control
    inline void move(int duration) override {};
    void jump() override;
    // Events
    void hitLeft() override;
    void hitRight() override;
    void hitGround() override;
    inline void recoil(int force, cpVect point) override {};

private:
    /* State change checkers */
    int ticksGrounded = 0;
    bool keepsSliding = true;
};

