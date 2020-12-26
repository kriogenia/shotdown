#pragma once

#include "Weapon.h"

/* Singleton */
class WeaponFactory
{
public:
    static WeaponFactory* getInstance(Game* game);
    /* Weapon generator */
    Weapon* getWeapon();
    Weapon* getRandomWeapon();

private:
    static WeaponFactory* instance;

    WeaponFactory(Game* game);

    /* Weapon pool */
    void fillPool();
    vector<Weapon*> weapons;
    vector<int> pool;
};
