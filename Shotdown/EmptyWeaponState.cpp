#include "EmptyWeaponState.h"

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
	// Play empty clip sound
}