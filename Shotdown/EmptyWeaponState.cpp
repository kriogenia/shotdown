#include "EmptyWeaponState.h"

#include "Broadcaster.h"

EmptyWeaponState::EmptyWeaponState(Weapon* weapon) :
	WeaponStateBase(weapon)
{
}

void EmptyWeaponState::enter()
{
	cout << weapon->owner->toString() << " " << weapon->toString() << " has no ammo left" << endl;
}

void EmptyWeaponState::shoot()
{
	weapon->messager->notify(Notifications::EMPTY_CLIP);
}