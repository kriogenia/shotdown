#pragma once

#include "ManualWeapon.h"

/* Ammo */
constexpr auto G3SG1_CLIP_SIZE = 6;
constexpr auto G3SG1_EXTRA_AMMO = 18;
/* Reload */
constexpr auto G3SG1_RELOAD_TIME = 3.3 * TARGET_FPS;
constexpr auto G3SG1_WAIT_TIME = 0.6 * static_cast<double>(TARGET_FPS);
/* Recoil */
constexpr auto G3SG1_RECOIL_FORCE = 140 * TARGET_FPS;
/* Projectile */
constexpr auto G3SG1_DAMAGE = 80;
constexpr auto G3SG1_PROJECTILE_LIFE = 0.8 * static_cast<double>(TARGET_FPS);
constexpr auto G3SG1_PROJECTILE_SPEED = 8.5;
/* Shot point */
constexpr auto G3SG1_SHOT_POINT_X = 32.0f;
constexpr auto G3SG1_SHOT_POINT_Y = 2.0f;
/* Audio */
constexpr auto G3SG1_SOUND = "res/audio/weapons/g3sg1.wav";
constexpr auto G3SG1_SPRITE = "res/weapons/g3sg1.png";             

class G3SG1 :
    public ManualWeapon
{
public:
    G3SG1(Game* game);
    /* Weapon */
    void shoot() override;
    /* Prototype */
    inline Weapon* clone() override { return new G3SG1(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "G3SG1"; };

};

