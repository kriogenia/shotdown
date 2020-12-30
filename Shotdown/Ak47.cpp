#include "Ak47.h"

Ak47::Ak47(Game* game) :
	AutomaticWeapon(AK47_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::UNCOMMON);
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
	damage = AK47_DAMAGE;
	projectileSpeed = AK47_PROJECTILE_SPEED;
	recoilPerShot = AK47_RECOIL_PER_SHOT;
	bulletLife = AK47_PROJECTILE_LIFE;
	// Sound
	sound = new SoundEffect(AK47_SOUND);
	/* AutomaticWeapon */
	anglePerShot = AK47_ANGLE_PER_SHOT;
}

Weapon* Ak47::clone(Player* owner)
{
	Weapon* clone = new Ak47(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}
