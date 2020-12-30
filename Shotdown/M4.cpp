#include "M4.h"

M4::M4(Game* game) :
	AutomaticWeapon(M4_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::COMMON);
	// Ammo
	clipSize = M4_CLIP_SIZE;
	loadedAmmo = M4_CLIP_SIZE;
	unloadedAmmo = M4_EXTRA_AMMO;
	// Cooldowns
	reloadTime = M4_RELOAD_TIME;
	shotCooldown = M4_WAIT_TIME;
	// Shooting
	recoil = M4_RECOIL_FORCE;
	shotPointOffset = { M4_SHOT_POINT_X , M4_SHOT_POINT_Y };
	// Projectile
	projectileSpeed = M4_PROJECTILE_SPEED;
	recoilPerShot = M4_RECOIL_PER_SHOT;
	bulletLife = M4_PROJECTILE_LIFE;
	// Sound
	sound = new SoundEffect(M4_SOUND);
	/* AutomaticWeapon */
	anglePerShot = M4_ANGLE_PER_SHOT;
}

Weapon* M4::clone(Player* owner)
{
	Weapon* clone = new M4(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}
