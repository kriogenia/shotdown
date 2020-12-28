#pragma once

#include "State.h"

enum class eWeaponStates {
    LOADED,
    RELOADING,
    EMPTY
};

/* Interface */
class WeaponState :
    public State
{
public:
    /* Shooting action */
    virtual void shoot() {};

};

