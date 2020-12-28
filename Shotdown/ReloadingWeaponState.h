#pragma once

#include "WeaponStateBase.h"

class ReloadingWeaponState :
    public WeaponStateBase
{
public:
    ReloadingWeaponState(Weapon* weapon);
    /* State */
    void enter() override;
    void tick() override;
    void exit() override;

};



