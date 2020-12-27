#pragma once

#include "PlayerState.h"

class DashingPlayerState :
    public PlayerState
{
public:
    DashingPlayerState(Player* player);
    /* State */
    void enter() override;
    void tick() override;
    void exit() override;
    /* Player state */
    // Controls
    inline void move(int direction) override {};
    inline void jump() override {};
    inline void pressTrigger() override{};
    // Events
    void hitLeft() override;
    void hitRight() override;

private:
    float remainingDuration = PLAYER_DASH_DURATION;
};

