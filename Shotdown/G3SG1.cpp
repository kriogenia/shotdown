#include "G3SG1.h"

G3SG1::G3SG1(Game* game) :
	ManualWeapon(G3SG1_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::RARE);
	// Ammo
	clipSize = G3SG1_CLIP_SIZE;
	loadedAmmo = G3SG1_CLIP_SIZE;
	unloadedAmmo = G3SG1_EXTRA_AMMO;
	// Cooldowns
	reloadTime = G3SG1_RELOAD_TIME;
	shotCooldown = G3SG1_WAIT_TIME;
	// Shooting
	recoil = G3SG1_RECOIL_FORCE;
	shotPointOffset = { G3SG1_SHOT_POINT_X , G3SG1_SHOT_POINT_Y };
	// Projectile
	damage = G3SG1_DAMAGE;
	projectileSpeed = G3SG1_PROJECTILE_SPEED;
	// Sound
	bulletLife = G3SG1_PROJECTILE_LIFE;
	sound = new SoundEffect(G3SG1_SOUND);
}

Weapon* G3SG1::clone(Player* owner)
{
	Weapon* clone = new G3SG1(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}

void G3SG1::shoot()
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