#pragma once

#include "WeaponStateBase.h"

class LoadedWeaponState :
    public WeaponStateBase
{
public:
    LoadedWeaponState(Weapon* weapon);
    /* State */
    void exit() override;
    /* WeaponState */
    void shoot() override;

};

