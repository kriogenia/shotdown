#pragma once

#include "Player.h"
#include "Weapon.h"

/* Singleton */
class StateFactory
{
public:
    static StateFactory* getInstance();
    /* State generator */
    PlayerState* getState(ePlayerStates stateId, Player* player);
    WeaponState* getState(eWeaponStates stateId, Weapon* weapon);

private:
    static StateFactory* instance;

    StateFactory();
};
