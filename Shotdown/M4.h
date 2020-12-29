#pragma once

#include "AutomaticWeapon.h"

/* Ammo */
constexpr auto M4_CLIP_SIZE = 10;
constexpr auto M4_EXTRA_AMMO = 10;
/* Reload */
constexpr auto M4_RELOAD_TIME = 2 * TARGET_FPS; // 2s
constexpr auto M4_WAIT_TIME = 0.2 * static_cast<double>(TARGET_FPS); // 0.2s
/* Recoil */
constexpr auto M4_RECOIL_PER_SHOT = 0.15;
constexpr float M4_ANGLE_PER_SHOT = 0.7;
constexpr auto M4_RECOIL_FORCE = 40 * TARGET_FPS;
/* Projectile */
constexpr auto M4_PROJECTILE_LIFE = 0.6 * static_cast<double>(TARGET_FPS); // 0.5s
constexpr auto M4_PROJECTILE_SPEED = 4.5;
/* Shot point */
constexpr auto M4_SHOT_POINT_X = 12.0;
constexpr auto M4_SHOT_POINT_Y = -3.0;
/* Audio */
constexpr auto M4_SOUND = "res/audio/weapons/m4.wav";
constexpr auto M4_SPRITE = "res/weapons/m4.png";

class M4 :
    public AutomaticWeapon
{
public:
    M4(Game* game);
    /* Prototype */
    inline Weapon* clone() override { return new M4(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "M4"; };

};

