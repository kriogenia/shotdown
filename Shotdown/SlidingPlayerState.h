#pragma once

#include "PlayerState.h"

constexpr auto SLIDING_SPEED = 2.5;
constexpr auto WALL_JUMP_X = 16;
constexpr auto WALL_JUMP_Y = 48;

class SlidingPlayerState :
    public PlayerState
{
public:
    SlidingPlayerState(Player* player);
    /* State */
    void enter() override;
    void update() override;
    /* PlayerState */
    // Control
    void move(int duration) override {};
    void jump() override;
    // Interaction
    void hitLeft() override;
    void hitRight() override;
    void hitGround() override;

private:
    /* State change checkers */
    int ticksGrounded = 0;
    bool keepsSliding = true;
};

