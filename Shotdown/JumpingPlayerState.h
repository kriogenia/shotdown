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
    void move(int direction);
    void jump() override;

private:
    int ticksFalling = 0;
};
