#pragma once

#include "Weapon.h"

constexpr auto AK47_CLIP_SIZE = 10;
constexpr auto AK47_EXTRA_AMMO = 10;
constexpr auto AK47_RECOIL = 45 * TARGET_FPS;

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
    inline Weapon* clone() override { return new Ak47(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "AK-47"; };

private:
    /* Function */
    void shoot() override;
    /* State */
    bool shooting = false;
};

