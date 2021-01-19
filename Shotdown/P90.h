#pragma once

#include "AutomaticWeapon.h"

/* Ammo */
constexpr auto P90_CLIP_SIZE = 15;
constexpr auto P90_EXTRA_AMMO = 30;
/* Reload */
constexpr auto P90_RELOAD_TIME = 3.3 * TARGET_FPS;
constexpr auto P90_WAIT_TIME = 0.2 * static_cast<double>(TARGET_FPS);
/* Recoil */
constexpr auto P90_RECOIL_PER_SHOT = 0.3;
constexpr float P90_ANGLE_PER_SHOT = 1.3;
constexpr auto P90_RECOIL_FORCE = 60 * TARGET_FPS;
/* Projectile */
constexpr auto P90_DAMAGE = 26;
constexpr auto P90_PROJECTILE_LIFE = 0.4 * static_cast<double>(TARGET_FPS);
constexpr auto P90_PROJECTILE_SPEED = 6.0;
/* Shot point */
constexpr auto P90_SHOT_POINT_X = 12.0f;
constexpr auto P90_SHOT_POINT_Y = 2.0f;
/* Audio */
constexpr auto P90_SOUND = "res/audio/weapons/p90.wav";
constexpr auto P90_SPRITE = "res/weapons/p90.png";

class P90 :
    public AutomaticWeapon
{
public:
    P90(Game* game);
    /* Prototype */
    inline Weapon* clone() override { return new P90(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "P90"; };

};

