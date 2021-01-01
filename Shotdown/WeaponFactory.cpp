#include "WeaponFactory.h"

#include "Ak47.h"
#include "AWP.h"
#include "Galil.h"
#include "M4.h"
#include "Mac10.h"
#include "Nova.h"
#include "P90.h"
#include "SawedOff.h"
#include "Tec9.h"
#include "Trabuco.h"

WeaponFactory* WeaponFactory::instance = 0;

WeaponFactory* WeaponFactory::getInstance(Game* game) 
{
    if (instance == 0)
        instance = new WeaponFactory(game);
    return instance;
}

WeaponFactory::WeaponFactory(Game* game) 
{
    /* Add a copy of each weapon to clone */
    // Rifles
    weapons.push_back(new M4(game));        // common
    weapons.push_back(new Ak47(game));      // uncommon
    weapons.push_back(new Galil(game));     // rare
    // Shotguns
    weapons.push_back(new Nova(game));      // common
    weapons.push_back(new SawedOff(game));  // uncommon
    weapons.push_back(new Trabuco(game));   // rare
    // SMGs
    weapons.push_back(new Tec9(game));      // common
    weapons.push_back(new Mac10(game));     // uncommon
    weapons.push_back(new P90(game));       // rare
    // Snipers
    weapons.push_back(new AWP(game));       // uncommon
    // Fill the pool
    fillPool();
}

/* Get a random weapon from the avaliable pool */
Weapon* WeaponFactory::getWeapon()
{
    return weapons[9]->clone();     // Debug
    int position = rand() % pool.size();
    Weapon* weapon = weapons[pool[position]]->clone();
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
    for (unsigned int i = 0; i < weapons.size(); i++) {
        int copies = weapons[i]->rarity;
        for (int j = 0; j < copies; j++) {
            pool.push_back(i);
        }
    }
}