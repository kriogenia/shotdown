#include "ReloadingWeaponState.h"
#include "StateFactory.h"

ReloadingWeaponState::ReloadingWeaponState(Weapon* weapon) :
    WeaponStateBase(weapon)
{
}

void ReloadingWeaponState::enter()
{
    printf("%s %s reloading\n", weapon->owner->toString().c_str(), weapon->toString().c_str());
    weapon->reloadTimeLeft = weapon->reloadTime;
    messager->notify(Notifications::START_RELOAD);
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