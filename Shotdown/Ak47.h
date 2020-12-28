#pragma once

#include "AutomaticWeapon.h"

/* Ammo */
constexpr auto AK47_CLIP_SIZE = 10;
constexpr auto AK47_EXTRA_AMMO = 10;
/* Reload */
constexpr auto AK47_RELOAD_TIME = 2 * TARGET_FPS; // 2s
constexpr auto AK47_WAIT_TIME = 0.2 * TARGET_FPS; // 0.2s
/* Recoil */
constexpr auto AK47_RECOIL_PER_SHOT = 0.25;
constexpr auto AK47_ANGLE_PER_SHOT = 1.9;
constexpr auto AK47_RECOIL_FORCE = 60 * TARGET_FPS;
/* Projectile */
constexpr auto AK47_PROJECTILE_LIFE = 0.5 * TARGET_FPS; // 0.5s
constexpr auto AK47_PROJECTILE_SPEED = 5.0;
/* Shot point */
constexpr auto AK47_SHOT_POINT_X = 12.0;
constexpr auto AK47_SHOT_POINT_Y = -4.0;
/* Audio */
constexpr auto AK47_SOUND = "res/audio/weapons/ak47.wav";

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

