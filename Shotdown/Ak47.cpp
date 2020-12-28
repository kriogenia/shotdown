#include "Ak47.h"

Ak47::Ak47(Game* game) :
	AutomaticWeapon("res/weapons/ak47.png", 30, 8, 30, 8, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::COMMON);
	// Ammo
	clipSize = AK47_CLIP_SIZE;
	loadedAmmo = AK47_CLIP_SIZE;
	unloadedAmmo = AK47_EXTRA_AMMO;
	// Cooldowns
	reloadTime = AK47_RELOAD_TIME;
	shotCooldown = AK47_WAIT_TIME;
	// Shooting
	recoil = AK47_RECOIL_FORCE;
	shotPointOffset = { AK47_SHOT_POINT_X , AK47_SHOT_POINT_Y };
	// Projectile
	projectileSpeed = AK47_PROJECTILE_SPEED;
	recoilPerShot = AK47_RECOIL_PER_SHOT;
	/* AutomaticWeapon */
	anglePerShot = AK47_ANGLE_PER_SHOT;
	bulletLife = AK47_PROJECTILE_LIFE;
}

Weapon* Ak47::clone(Player* owner)
{
	Weapon* clone = new Ak47(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}
