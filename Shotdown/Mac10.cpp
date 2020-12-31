#include "Mac10.h"

Mac10::Mac10(Game* game) :
	AutomaticWeapon(MAC10_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::UNCOMMON);
	// Ammo
	clipSize = MAC10_CLIP_SIZE;
	loadedAmmo = MAC10_CLIP_SIZE;
	unloadedAmmo = MAC10_EXTRA_AMMO;
	// Cooldowns
	reloadTime = MAC10_RELOAD_TIME;
	shotCooldown = MAC10_WAIT_TIME;
	// Shooting
	recoil = MAC10_RECOIL_FORCE;
	shotPointOffset = { MAC10_SHOT_POINT_X , MAC10_SHOT_POINT_Y };
	// Projectile
	damage = MAC10_DAMAGE;
	projectileSpeed = MAC10_PROJECTILE_SPEED;
	recoilPerShot = MAC10_RECOIL_PER_SHOT;
	bulletLife = MAC10_PROJECTILE_LIFE;
	// Sound
	sound = new SoundEffect(MAC10_SOUND);
	/* AutomaticWeapon */
	anglePerShot = MAC10_ANGLE_PER_SHOT;
}

Weapon* Mac10::clone(Player* owner)
{
	Weapon* clone = new Mac10(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}
