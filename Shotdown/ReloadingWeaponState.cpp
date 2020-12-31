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
    messager->notify(Notifications::START_RELOAD, weapon->owner);
}

void ReloadingWeaponState::tick()
{
    weapon->reloadTimeLeft--;
    if (weapon->reloadTimeLeft <= 0) {
        weapon->setState(eWeaponStates::LOADED);
    }
}

void ReloadingWeaponState::exit()
{
    cout << weapon->owner->toString() << " " << weapon->toString() << " reloaded" << endl;
    weapon->loadedAmmo = weapon->clipSize;
    weapon->unloadedAmmo -= weapon->clipSize;
    messager->notify(Notifications::END_RELOAD, weapon->owner);
}