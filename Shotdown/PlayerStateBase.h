#pragma once

#include "Broadcaster.h"
#include "Player.h"
#include "PlayerState.h"

class PlayerStateBase :
    public PlayerState
{
public:
    PlayerStateBase(Player* actor);
    /* PlayerState */
    // Control
    void move(int direction) override;
    void jump() override;
    void dash() override;
    void pressTrigger() override;
    void releaseTrigger() override;
    // Events
    void impacted(PlayerTag shooter, cpVect velocity) override;
    void recoil(int force, cpVect point) override;

protected:
    /* References */
    Broadcaster* messager = Broadcaster::getInstance();
    Player* player;
    /* Orientation */
    void setOrientation(int direction);

};

