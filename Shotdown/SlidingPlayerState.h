#pragma once

#include "PlayerStateBase.h"

class SlidingPlayerState :
    public PlayerStateBase
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
    void impacted(PlayerTag shooter, int damage, cpVect velocity);
    inline void recoil(int force, cpVect point) override {};
    void hitLeft() override;
    void hitRight() override;
    void hitGround() override;

private:
    /* State change checkers */
    int ticksGrounded = 0;
    bool keepsSliding = true;
};

