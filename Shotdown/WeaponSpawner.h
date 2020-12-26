#pragma once

#include "WeaponFactory.h"

constexpr auto RANDOM_SPAWNER_RARITY = 10;

class WeaponSpawner :
    public Actor
{
public:
    WeaponSpawner(float x, float y, Game* game);
    /* Actor */
    void render() override;

private:
    /* Weapon */
    void getWeapon();
    Weapon* weapon = nullptr;
    /* Type */
    bool random = false;
    Actor* randomDisplay = nullptr;
};

