#pragma once

#include "AutomaticWeapon.h"

constexpr auto AK47_CLIP_SIZE = 10;
constexpr auto AK47_EXTRA_AMMO = 10;
constexpr auto AK47_RECOIL_PER_SHOT = 0.25;
constexpr auto AK47_RECOIL_FORCE = 45 * TARGET_FPS;
/* Projectile */
constexpr auto AK47_PROJECTILE_LIFE = 30; // 0.5s
constexpr auto AK47_PROJECTILE_SPEED = 5.0;
/* Shot point */
constexpr auto AK47_SHOT_POINT_X = 12.0;
constexpr auto AK47_SHOT_POINT_Y = -4.0;

class Ak47 :
    public AutomaticWeapon
{
public:
    Ak47(Game* game);
    /* Prototype */
    inline Weapon* clone() override { return new Ak47(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "AK-47"; };

};

