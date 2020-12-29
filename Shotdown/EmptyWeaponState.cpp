#include "EmptyWeaponState.h"

#include "Broadcaster.h"

EmptyWeaponState::EmptyWeaponState(Weapon* weapon) :
	WeaponStateBase(weapon)
{
}

void EmptyWeaponState::enter()
{
	printf("%s %s has no ammo left\n", weapon->owner->toString().c_str(), weapon->toString().c_str());
}

void EmptyWeaponState::shoot()
{
	weapon->messager->notify(Notifications::EMPTY_CLIP);
}