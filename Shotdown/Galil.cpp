#include "Galil.h"

Galil::Galil(Game* game) :
	AutomaticWeapon(GALIL_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::RARE);
	// Ammo
	clipSize = GALIL_CLIP_SIZE;
	loadedAmmo = GALIL_CLIP_SIZE;
	unloadedAmmo = GALIL_EXTRA_AMMO;
	// Cooldowns
	reloadTime = GALIL_RELOAD_TIME;
	shotCooldown = GALIL_WAIT_TIME;
	// Shooting
	recoil = GALIL_RECOIL_FORCE;
	shotPointOffset = { GALIL_SHOT_POINT_X , GALIL_SHOT_POINT_Y };
	// Projectile
	projectileSpeed = GALIL_PROJECTILE_SPEED;
	recoilPerShot = GALIL_RECOIL_PER_SHOT;
	bulletLife = GALIL_PROJECTILE_LIFE;
	// Sound
	sound = new SoundEffect(GALIL_SOUND);
	/* AutomaticWeapon */
	anglePerShot = GALIL_ANGLE_PER_SHOT;
}

Weapon* Galil::clone(Player* owner)
{
	Weapon* clone = new Galil(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}
