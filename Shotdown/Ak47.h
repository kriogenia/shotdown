#pragma once

#include "Weapon.h"

constexpr auto AK47_CLIP_SIZE = 10;
constexpr auto AK47_EXTRA_AMMO = 10;

class Ak47 :
    public Weapon
{
public:
    Ak47(Game* game);
    /* Game cycle */
    void tick() override;
    /* Control */
    void pressTrigger() override;
    void releaseTrigger() override;
    /* Prototype */
    Weapon* clone() override;
    Weapon* clone(Player* owner) override;

private:
    bool shooting;
};

