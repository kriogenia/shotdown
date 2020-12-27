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

class AutomaticWeapon :
    public Weapon
{
public:
    AutomaticWeapon(string filename, int width, int height, int fileWidth, int fileHeight, Game* game);
    /* Game cycle */
    void tick() override;
    void render(float rotation = 0.0) override;
    /* Control */
    void pressTrigger() override;
    void releaseTrigger() override;

private:
    /* Function */
    void shoot() override;
    /* State */
    bool shooting = false;
    int consecutiveShots = 0;
};
