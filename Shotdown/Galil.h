#pragma once

#include "AutomaticWeapon.h"

/* Ammo */
constexpr auto GALIL_CLIP_SIZE = 12;
constexpr auto GALIL_EXTRA_AMMO = 24;
/* Reload */
constexpr auto GALIL_RELOAD_TIME = 3 * TARGET_FPS; // 3s
constexpr auto GALIL_WAIT_TIME = 0.27 * static_cast<double>(TARGET_FPS); // 0.27s
/* Recoil */
constexpr auto GALIL_RECOIL_PER_SHOT = 0.2;
constexpr float GALIL_ANGLE_PER_SHOT = 1.1;
constexpr auto GALIL_RECOIL_FORCE = 45 * TARGET_FPS;
/* Projectile */
constexpr auto GALIL_DAMAGE = 30;
constexpr auto GALIL_PROJECTILE_LIFE = 0.7 * static_cast<double>(TARGET_FPS); // 0.7s
constexpr auto GALIL_PROJECTILE_SPEED = 6.2;
/* Shot point */
constexpr auto GALIL_SHOT_POINT_X = 12.0;
constexpr auto GALIL_SHOT_POINT_Y = -4.0;
/* Audio */
constexpr auto GALIL_SOUND = "res/audio/weapons/ak47.wav";
constexpr auto GALIL_SPRITE = "res/weapons/ak47.png";       // Placeholder

class Galil :
    public AutomaticWeapon
{
public:
    Galil(Game* game);
    /* Prototype */
    inline Weapon* clone() override { return new Galil(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "Galil"; };

};

