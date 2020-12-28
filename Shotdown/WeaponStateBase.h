#pragma once

#include "Weapon.h"

class WeaponStateBase :
    public WeaponState
{
public:
    WeaponStateBase(Weapon* weapon);

protected:
    Weapon* weapon;
};

