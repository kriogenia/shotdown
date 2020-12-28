#include "ReloadingWeaponState.h"
#include "StateFactory.h"

ReloadingWeaponState::ReloadingWeaponState(Weapon* weapon) :
    WeaponStateBase(weapon)
{
}

void ReloadingWeaponState::enter()
{
    cout << weapon->owner->toString() << " " << weapon->toString() << " reloading" << endl;
    weapon->reloadTimeLeft = weapon->reloadTime;
    // call to HUD -> make reload animation visible
}

void ReloadingWeaponState::tick()
{
    weapon->reloadTime--;
    if (weapon->reloadTime <= 0) {
        weapon->setState(eWeaponStates::LOADED);
    }
    // update HUD
}

void ReloadingWeaponState::exit()
{
    cout << weapon->owner->toString() << " " << weapon->toString() << " reloaded" << endl;
    weapon->loadedAmmo = weapon->clipSize;
    weapon->unloadedAmmo -= weapon->clipSize;
    // make HUD not visible
}