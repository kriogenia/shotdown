#pragma once

#include "Weapon.h"

constexpr auto AK47_CLIP_SIZE = 10;
constexpr auto AK47_EXTRA_AMMO = 10;
constexpr auto AK47_RECOIL_PER_SHOT = 0.25;
constexpr auto AK47_RECOIL_FORCE = 45 * TARGET_FPS;
constexpr auto AK47_BULLET_LIFE = 30; // 0.5s
/* Shot point */
constexpr auto AK47_SHOT_POINT_X = 12.0;
constexpr auto AK47_SHOT_POINT_Y = -4.0;

class Ak47 :
    public Weapon
{
public:
    Ak47(Game* game);
    /* Game cycle */
    void tick() override;
    void render(float rotation = 0.0) override;
    /* Control */
    void pressTrigger() override;
    void releaseTrigger() override;
    /* Prototype */
    inline Weapon* clone() override { return new Ak47(game); };
    Weapon* clone(Player* owner) override;
    /* Debug */
    inline string toString() override { return "AK-47"; };

private:
    /* Function */
    void shoot() override;
    /* State */
    bool shooting = false;
    int consecutiveShots = 0;
};

