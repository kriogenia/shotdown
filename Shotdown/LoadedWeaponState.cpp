#include "LoadedWeaponState.h"

LoadedWeaponState::LoadedWeaponState(Weapon* weapon) :
    WeaponStateBase(weapon)
{
}

void LoadedWeaponState::exit()
{
    printf("%s %s clip is empty\n", weapon->owner->toString().c_str(), weapon->toString().c_str());
}

void LoadedWeaponState::shoot()
{
    weapon->shoot();
    if (weapon->loadedAmmo <= 0) {
        if (weapon->unloadedAmmo > 0) {
            weapon->setState(eWeaponStates::RELOADING);
        }
        else {
            weapon->setState(eWeaponStates::EMPTY);
        }
    }
}