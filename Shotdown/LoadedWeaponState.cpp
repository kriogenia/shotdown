#include "LoadedWeaponState.h"

LoadedWeaponState::LoadedWeaponState(Weapon* weapon) :
    WeaponStateBase(weapon)
{
}

void LoadedWeaponState::exit()
{
    cout << weapon->owner->toString() << " " << weapon->toString() << " clip is empty" << endl;
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