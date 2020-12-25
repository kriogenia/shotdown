#pragma once

#include "PlayerState.h"

class MovingPlayerState :
    public PlayerState
{
public:
    MovingPlayerState(Player* actor);
    /* State */
    void enter() override;
    void update() override;
    /* Player control */
    void move(int direction) override;
    void jump() override;

};