#include "Trabuco.h"

Trabuco::Trabuco(Game* game) :
	ManualWeapon(TRABUCO_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::RARE);
	// Ammo
	clipSize = TRABUCO_CLIP_SIZE;
	loadedAmmo = TRABUCO_CLIP_SIZE;
	unloadedAmmo = TRABUCO_EXTRA_AMMO;
	// Cooldowns
	reloadTime = TRABUCO_RELOAD_TIME;
	shotCooldown = TRABUCO_WAIT_TIME;
	// Shooting
	recoil = TRABUCO_RECOIL_FORCE;
	shotPointOffset = { TRABUCO_SHOT_POINT_X , TRABUCO_SHOT_POINT_Y };
	// Projectile
	damage = TRABUCO_DAMAGE;
	projectileSpeed = TRABUCO_PROJECTILE_SPEED;
	// Sound
	bulletLife = TRABUCO_PROJECTILE_LIFE;
	sound = new SoundEffect(TRABUCO_SOUND);
}

Weapon* Trabuco::clone(Player* owner)
{
	Weapon* clone = new Trabuco(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}

void Trabuco::shoot()
{
	Weapon::shoot();
	Projectile* projectile;
	float orientation = static_cast<float>(owner->orientation);
	// Fires projectiles
	for (int i = 0; i < TRABUCO_PELLETS; i++) {
		float dispersion = static_cast <float> (rand());
		dispersion /= (static_cast <float> (RAND_MAX / (TRABUCO_DISPERSION * 2)));
		dispersion -= TRABUCO_DISPERSION;
		projectile = new Projectile(owner->tag, damage, bulletLife, shotPoint.x,
			shotPoint.y + dispersion, game);
		engine->addActor(projectile);
		owner->projectiles->push_back(projectile);
		cpBodyApplyImpulseAtLocalPoint(projectile->body,
			cpv(orientation * projectileSpeed, dispersion),
			cpv(shotPoint.x, shotPoint.y));
	}
}