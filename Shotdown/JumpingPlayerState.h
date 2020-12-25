#pragma once

#include "PlayerState.h"

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
    void move(int direction);
    void jump() override;
    // Interaction
    void hitTop() override;
    void hitLeft() override;
    void hitRight() override;

private:
    int ticksFalling = 0;
};
