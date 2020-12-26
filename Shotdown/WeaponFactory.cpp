#include "WeaponFactory.h"

#include "Ak47.h"

WeaponFactory* WeaponFactory::instance = 0;

WeaponFactory* WeaponFactory::getInstance(Game* game) 
{
    if (instance == 0)
        instance = new WeaponFactory(game);
    return instance;
}

WeaponFactory::WeaponFactory(Game* game) 
{
    // Add a copy of each weapon to clone
    weapons.push_back(new Ak47(game));
    // Fill the pool
    fillPool();
}

/* Get a random weapon from the avaliable pool */
Weapon* WeaponFactory::getWeapon()
{
    int position = rand() % pool.size();
    Weapon* weapon = weapons[position]->clone();
    pool.erase(pool.begin() + position);
    if (pool.size() <= 0) {
        fillPool();
    }
    return weapon;
}

/* Get a copy of a random weapon (non rarity weighted) */
Weapon* WeaponFactory::getRandomWeapon()
{
    return weapons[rand() % weapons.size()]->clone();
}

/* Add weapons based on rarity to the pool */
void WeaponFactory::fillPool()
{
    for (int i = 0; i < weapons.size(); i++) {
        int copies = weapons[i]->rarity;
        for (int j = 0; j < copies; j++) {
            pool.push_back(i);
        }
    }
}