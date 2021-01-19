#pragma once

#include "Animation.h"
#include "Broadcaster.h"
#include "Player.h"
#include "PlayerState.h"

constexpr auto PLAYER_ANIM_FILE_WIDTH = 120;
constexpr auto PLAYER_ANIM_FILE_HEIGHT = 256;

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
    void setAnimation(bool loop);
    Animation* animation = nullptr;

};

