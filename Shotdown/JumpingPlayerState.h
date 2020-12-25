#pragma once

#include "PlayerState.h"

constexpr auto TICKS_TO_STOP = 3;

class JumpingPlayerState :
    public PlayerState
{
public:
    JumpingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void update() override;
    void exit() override;
    /* Player control */
    void move(int direction) override;
    void jump() override;

private:
    int stopCounter = TICKS_TO_STOP;
};
