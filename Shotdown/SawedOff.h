#pragma once

#include "ManualWeapon.h"

/* Ammo */
constexpr auto SAWED_OFF_CLIP_SIZE = 2;
constexpr auto SAWED_OFF_EXTRA_AMMO = 6;
/* Reload */
constexpr auto SAWED_OFF_RELOAD_TIME = 3.2 * TARGET_FPS; 
constexpr auto SAWED_OFF_WAIT_TIME = 0.77 * static_cast<double>(TARGET_FPS); 
/* Recoil */
constexpr auto SAWED_OFF_RECOIL_FORCE = 180 * TARGET_FPS;
/* Projectile */
constexpr auto SAWED_OFF_DAMAGE = 32;
constexpr auto SAWED_OFF_PELLETS = 5;
constexpr auto SAWED_OFF_DISPERSION = 0.5;
constexpr auto SAWED_OFF_PROJECTILE_LIFE = 0.35 * static_cast<double>(TARGET_FPS); 
constexpr auto SAWED_OFF_PROJECTILE_SPEED = 5.5;
/* Shot point */
constexpr auto SAWED_OFF_SHOT_POINT_X = 12.0;
constexpr auto SAWED_OFF_SHOT_POINT_Y = -4.0;
/* Audio */
constexpr auto SAWED_OFF_SOUND = "res/audio/weapons/sawed-off.wav";  // 
constexpr auto SAWED_OFF_SPRITE = "res/weapons/nova.png";       // Placeholder

class SawedOff :
    public ManualWeapon
{
public:
    SawedOff(Game* game);
    /* Weapon */
    void shoot() override;
    /* Prototype */
    inline Weapon* clone() override { return new SawedOff(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "Sawed-Off Shotgun"; };

};

