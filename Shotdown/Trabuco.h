#pragma once

#include "ManualWeapon.h"

/* Ammo */
constexpr auto TRABUCO_CLIP_SIZE = 1;
constexpr auto TRABUCO_EXTRA_AMMO = 7;
/* Reload */
constexpr auto TRABUCO_RELOAD_TIME = 4 * TARGET_FPS;
constexpr auto TRABUCO_WAIT_TIME = 2.2 * static_cast<double>(TARGET_FPS);
/* Recoil */
constexpr auto TRABUCO_RECOIL_FORCE = 211 * TARGET_FPS;
/* Projectile */
constexpr auto TRABUCO_DAMAGE = 44;
constexpr auto TRABUCO_PELLETS = 8;
constexpr auto TRABUCO_DISPERSION = 0.8;
constexpr auto TRABUCO_PROJECTILE_LIFE = 0.8 * static_cast<double>(TARGET_FPS);
constexpr auto TRABUCO_PROJECTILE_SPEED = 2.0;
/* Shot point */
constexpr auto TRABUCO_SHOT_POINT_X = 12.0;
constexpr auto TRABUCO_SHOT_POINT_Y = -4.0;
/* Audio */
constexpr auto TRABUCO_SOUND = "res/audio/weapons/trabuco.wav";
constexpr auto TRABUCO_SPRITE = "res/weapons/nova.png";         // Placeholder

class Trabuco :
    public ManualWeapon
{
public:
    Trabuco(Game* game);
    /* Weapon */
    void shoot() override;
    /* Prototype */
    inline Weapon* clone() override { return new Trabuco(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "El Trabuco"; };

};

