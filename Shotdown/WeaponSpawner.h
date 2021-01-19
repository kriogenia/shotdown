#pragma once

#include "Animation.h"
#include "Player.h"
#include "WeaponFactory.h"

constexpr auto SPAWNER_CD = 10 * TARGET_FPS;        // 10s
constexpr auto RANDOM_SPAWNER_RARITY = 5;           // 1 out of 5

class WeaponSpawner :
    public Actor
{
public:
    WeaponSpawner(float x, float y, Game* game);
    /* Actor */
    void tick() override;
    void render(float rotation = 0.0) override;
    /* Events */
    bool pickWeapon(Player* player);

private:
    /* Animation */
    Animation* animation = nullptr;
    /* State */
    int cooldown = SPAWNER_CD;
    /* Weapon */
    void getWeapon();
    Weapon* weapon = nullptr;
    /* Type */
    bool random = false;
    Actor* randomDisplay = nullptr;
};

