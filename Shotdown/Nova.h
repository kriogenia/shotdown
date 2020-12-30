#pragma once

#include "ManualWeapon.h"

/* Ammo */
constexpr auto NOVA_CLIP_SIZE = 3;
constexpr auto NOVA_EXTRA_AMMO = 6;
/* Reload */
constexpr auto NOVA_RELOAD_TIME = 2.4 * TARGET_FPS; // 2.4s
constexpr auto NOVA_WAIT_TIME = 0.8 * static_cast<double>(TARGET_FPS); // 1.1s
/* Recoil */
constexpr auto NOVA_RECOIL_FORCE = 120 * TARGET_FPS;
/* Projectile */
constexpr auto NOVA_PELLETS = 3;
constexpr auto NOVA_DISPERSION = 1;
constexpr auto NOVA_PROJECTILE_LIFE = 0.3 * static_cast<double>(TARGET_FPS); // 0.3s
constexpr auto NOVA_PROJECTILE_SPEED = 5.0;
/* Shot point */
constexpr auto NOVA_SHOT_POINT_X = 12.0;
constexpr auto NOVA_SHOT_POINT_Y = -4.0;
/* Audio */
constexpr auto NOVA_SOUND = "res/audio/weapons/nova.wav";
constexpr auto NOVA_SPRITE = "res/weapons/nova.png";

class Nova :
    public ManualWeapon
{
public:
    Nova(Game* game);
    /* Weapon */
    void shoot() override;
    /* Prototype */
    inline Weapon* clone() override { return new Nova(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "Nova"; };

};

