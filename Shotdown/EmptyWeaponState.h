#pragma once

#include "WeaponStateBase.h"

class EmptyWeaponState :
    public WeaponStateBase
{
public:
    EmptyWeaponState(Weapon* weapon);
    /* State */
    void enter();
    /* WeaponState */
    void shoot();
};

