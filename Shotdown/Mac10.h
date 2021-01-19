#pragma once

#include "AutomaticWeapon.h"

/* Ammo */
constexpr auto MAC10_CLIP_SIZE = 10;
constexpr auto MAC10_EXTRA_AMMO = 10;
/* Reload */
constexpr auto MAC10_RELOAD_TIME = 2.6 * TARGET_FPS;
constexpr auto MAC10_WAIT_TIME = 0.22 * static_cast<double>(TARGET_FPS);
/* Recoil */
constexpr auto MAC10_RECOIL_PER_SHOT = 0.2;
constexpr float MAC10_ANGLE_PER_SHOT = 1.1;
constexpr auto MAC10_RECOIL_FORCE = 65 * TARGET_FPS;
/* Projectile */
constexpr auto MAC10_DAMAGE = 29;
constexpr auto MAC10_PROJECTILE_LIFE = 0.4 * static_cast<double>(TARGET_FPS);
constexpr auto MAC10_PROJECTILE_SPEED = 5.0;
/* Shot point */
constexpr auto MAC10_SHOT_POINT_X = 10.0f;
constexpr auto MAC10_SHOT_POINT_Y = 1.0f;
/* Audio */
constexpr auto MAC10_SOUND = "res/audio/weapons/p90.wav";
constexpr auto MAC10_SPRITE = "res/weapons/mac10.png";       

class Mac10 :
    public AutomaticWeapon
{
public:
    Mac10(Game* game);
    /* Prototype */
    inline Weapon* clone() override { return new Mac10(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "Mac-10"; };

};

