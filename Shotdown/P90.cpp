#include "P90.h"

P90::P90(Game* game) :
	AutomaticWeapon(P90_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::COMMON);
	// Ammo
	clipSize = P90_CLIP_SIZE;
	loadedAmmo = P90_CLIP_SIZE;
	unloadedAmmo = P90_EXTRA_AMMO;
	// Cooldowns
	reloadTime = P90_RELOAD_TIME;
	shotCooldown = P90_WAIT_TIME;
	// Shooting
	recoil = P90_RECOIL_FORCE;
	shotPointOffset = { P90_SHOT_POINT_X , P90_SHOT_POINT_Y };
	// Projectile
	projectileSpeed = P90_PROJECTILE_SPEED;
	recoilPerShot = P90_RECOIL_PER_SHOT;
	// Sound
	sound = new SoundEffect(P90_SOUND);
	/* AutomaticWeapon */
	anglePerShot = P90_ANGLE_PER_SHOT;
	bulletLife = P90_PROJECTILE_LIFE;
}

Weapon* P90::clone(Player* owner)
{
	Weapon* clone = new P90(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}
