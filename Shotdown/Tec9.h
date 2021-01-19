#pragma once

#include "AutomaticWeapon.h"

/* Ammo */
constexpr auto TEC9_CLIP_SIZE = 6;
constexpr auto TEC9_EXTRA_AMMO = 6;
/* Reload */
constexpr auto TEC9_RELOAD_TIME = 2.5 * TARGET_FPS;
constexpr auto TEC9_WAIT_TIME = 0.12 * static_cast<double>(TARGET_FPS);
/* Furry */
constexpr auto TEC9_FURRY_SIZE = 3;
constexpr auto TEC9_FURRY_CD = 0.75 * static_cast<double>(TARGET_FPS);
/* Recoil */
constexpr auto TEC9_RECOIL_PER_SHOT = 0.28;
constexpr float TEC9_ANGLE_PER_SHOT = 1.3;                  // Adapt
constexpr auto TEC9_RECOIL_FORCE = 40 * TARGET_FPS;
/* Projectile */
constexpr auto TEC9_DAMAGE = 26;
constexpr auto TEC9_PROJECTILE_LIFE = 0.4 * static_cast<double>(TARGET_FPS);
constexpr auto TEC9_PROJECTILE_SPEED = 6.0;
/* Shot point */
constexpr auto TEC9_SHOT_POINT_X = 5.0f;
constexpr auto TEC9_SHOT_POINT_Y = 1.0f;
/* Audio */
constexpr auto TEC9_SOUND = "res/audio/weapons/p90.wav";
constexpr auto TEC9_SPRITE = "res/weapons/tec9.png";         

class Tec9 :
    public AutomaticWeapon
{
public:
    Tec9(Game* game);
    /* Game cycle */
    void tick() override;
    /* Automatic weapon */
    void shoot() override;
    /* Prototype */
    inline Weapon* clone() override { return new Tec9(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "Tec-9"; };

private:
    int furryCd = 0;

};
