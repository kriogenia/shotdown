#pragma once

#include "Animation.h"
#include "Broadcaster.h"
#include "Player.h"
#include "PlayerState.h"

class PlayerStateBase :
    public PlayerState
{
public:
    PlayerStateBase(Player* actor);
    /* PlayerState */
    // Game cycle
    void tick() override;
    void render(float rotation = 0.0) override;
    // Control
    void move(int direction) override;
    void jump() override;
    void dash() override;
    void pressTrigger() override;
    void releaseTrigger() override;
    // Events
    void impacted(PlayerTag shooter, int damage, cpVect velocity) override;
    void recoil(int force, cpVect point) override;

protected:
    /* References */
    Broadcaster* messager = Broadcaster::getInstance();
    Player* player = nullptr;
    /* Orientation */
    void setOrientation(int direction);
    /* Animation */
    Animation* animation = nullptr;

};

