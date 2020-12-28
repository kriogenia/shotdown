#pragma once

#include "PlayerStateBase.h"

class IdlePlayerState :
    public PlayerStateBase
{
public:
    IdlePlayerState(Player* actor);
    /* State */
    void enter() override;
    void tick() override;
    /* PlayerState */
    // Control
    void move(int direction) override;
    void jump() override;

private:
    int ticksFalling = 0;

};