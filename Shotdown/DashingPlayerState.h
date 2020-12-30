#pragma once

#include "PlayerStateBase.h"

class DashingPlayerState :
    public PlayerStateBase
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
    void impacted(PlayerTag shooter, int damage, cpVect velocity);
    void hitLeft() override;
    void hitRight() override;

private:
    float remainingDuration = PLAYER_DASH_DURATION;
};

