#pragma once

#include "Player.h"
#include "PlayerState.h"

class PlayerStateBase :
    public PlayerState
{
public:
    PlayerStateBase(Player* actor);
    /* PlayerState */
    // Control
    virtual void move(int direction);
    virtual void jump();
    virtual void dash();
    virtual void pressTrigger();
    virtual void releaseTrigger();
    // Events
    virtual void recoil(int force, cpVect point);

protected:
    /* Context pointer */
    Player* player;
    /* Orientation */
    void setOrientation(int direction);

};

