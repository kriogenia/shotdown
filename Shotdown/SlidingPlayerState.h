#pragma once

#include "PlayerState.h"

constexpr auto SLIDING_SPEED = 2.5 * TARGET_FPS;
constexpr auto WALL_JUMP_IMPULSE_X = 180 * TARGET_FPS;
constexpr auto WALL_JUMP_IMPULSE_Y = 360 * TARGET_FPS;

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

