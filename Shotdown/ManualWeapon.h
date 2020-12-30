#pragma once

#include "Weapon.h"

class ManualWeapon :
    public Weapon
{
public:
    ManualWeapon(string filename, int width, int height, Game* game);
    /* Game cycle */
    void tick() override;
    /* Control */
    void pressTrigger() override;
    inline void releaseTrigger() override {};

};
