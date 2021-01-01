#include "AWP.h"

AWP::AWP(Game* game) :
	ManualWeapon(AWP_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::UNCOMMON);
	// Ammo
	clipSize = AWP_CLIP_SIZE;
	loadedAmmo = AWP_CLIP_SIZE;
	unloadedAmmo = AWP_EXTRA_AMMO;
	// Cooldowns
	reloadTime = AWP_RELOAD_TIME;
	shotCooldown = AWP_WAIT_TIME;
	// Shooting
	recoil = AWP_RECOIL_FORCE;
	shotPointOffset = { AWP_SHOT_POINT_X , AWP_SHOT_POINT_Y };
	// Projectile
	damage = AWP_DAMAGE;
	projectileSpeed = AWP_PROJECTILE_SPEED;
	// Sound
	bulletLife = AWP_PROJECTILE_LIFE;
	sound = new SoundEffect(AWP_SOUND);
}

Weapon* AWP::clone(Player* owner)
{
	Weapon* clone = new AWP(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}

void AWP::shoot()
{
	Weapon::shoot();
	float orientation = static_cast<float>(owner->orientation);
	Projectile* projectile = new Projectile(owner->tag, damage, bulletLife, 
		shotPoint.x, shotPoint.y, game);
	engine->addActor(projectile);
	owner->projectiles->push_back(projectile);
	cpBodyApplyImpulseAtLocalPoint(projectile->body,
			cpv(orientation * projectileSpeed, 0),
			cpv(shotPoint.x, shotPoint.y));
}