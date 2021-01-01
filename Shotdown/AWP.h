#pragma once

#include "ManualWeapon.h"

/* Ammo */
constexpr auto AWP_CLIP_SIZE = 3;
constexpr auto AWP_EXTRA_AMMO = 3;
/* Reload */
constexpr auto AWP_RELOAD_TIME = 3.7 * TARGET_FPS;
constexpr auto AWP_WAIT_TIME = 1 * static_cast<double>(TARGET_FPS); 
/* Recoil */
constexpr auto AWP_RECOIL_FORCE = 160 * TARGET_FPS;
/* Projectile */
constexpr auto AWP_DAMAGE = 115;
constexpr auto AWP_PROJECTILE_LIFE = 0.8 * static_cast<double>(TARGET_FPS);
constexpr auto AWP_PROJECTILE_SPEED = 8.5;
/* Shot point */
constexpr auto AWP_SHOT_POINT_X = 12.0;
constexpr auto AWP_SHOT_POINT_Y = -4.0;
/* Audio */
constexpr auto AWP_SOUND = "res/audio/weapons/awp.wav";
constexpr auto AWP_SPRITE = "res/weapons/m4.png";             // Placeholder

class AWP :
    public ManualWeapon
{
public:
    AWP(Game* game);
    /* Weapon */
    void shoot() override;
    /* Prototype */
    inline Weapon* clone() override { return new AWP(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "AWP"; };

};

