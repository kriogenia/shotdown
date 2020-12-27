#include "Ak47.h"

Ak47::Ak47(Game* game) :
	AutomaticWeapon("res/weapons/ak47.png", 30, 8, 30, 8, game)
{
	/* Weapon */
	rarity = COMMON;
	loadedAmmo = AK47_CLIP_SIZE;
	unloadedAmmo = AK47_EXTRA_AMMO;
	shotPointOffset = { AK47_SHOT_POINT_X , AK47_SHOT_POINT_Y };
	recoil = AK47_RECOIL_FORCE;
	/* AutomaticWeapon */
	bulletLife = AK47_PROJECTILE_LIFE;
	projectileSpeed = AK47_PROJECTILE_SPEED;
	recoilPerShot = AK47_RECOIL_PER_SHOT;
}

Weapon* Ak47::clone(Player* owner)
{
	Weapon* clone = new Ak47(game);
	clone->owner = owner;
	clone->position = owner->position;
	return clone;
}
