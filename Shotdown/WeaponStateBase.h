#pragma once

#include "Broadcaster.h"
#include "Weapon.h"

class WeaponStateBase :
    public WeaponState
{
public:
    WeaponStateBase(Weapon* weapon);

protected:
    /* References */
    Broadcaster* messager = Broadcaster::getInstance();
    Weapon* weapon;

};

