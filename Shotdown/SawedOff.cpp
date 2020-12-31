#include "SawedOff.h"

SawedOff::SawedOff(Game* game) :
	ManualWeapon(SAWED_OFF_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::UNCOMMON);
	// Ammo
	clipSize = SAWED_OFF_CLIP_SIZE;
	loadedAmmo = SAWED_OFF_CLIP_SIZE;
	unloadedAmmo = SAWED_OFF_EXTRA_AMMO;
	// Cooldowns
	reloadTime = SAWED_OFF_RELOAD_TIME;
	shotCooldown = SAWED_OFF_WAIT_TIME;
	// Shooting
	recoil = SAWED_OFF_RECOIL_FORCE;
	shotPointOffset = { SAWED_OFF_SHOT_POINT_X , SAWED_OFF_SHOT_POINT_Y };
	// Projectile
	damage = SAWED_OFF_DAMAGE;
	projectileSpeed = SAWED_OFF_PROJECTILE_SPEED;
	// Sound
	bulletLife = SAWED_OFF_PROJECTILE_LIFE;
	sound = new SoundEffect(SAWED_OFF_SOUND);
}

Weapon* SawedOff::clone(Player* owner)
{
	Weapon* clone = new SawedOff(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}

void SawedOff::shoot()
{
	Weapon::shoot();
	Projectile* projectile;
	float orientation = static_cast<float>(owner->orientation);
	// Fires projectiles
	for (int i = 0; i < SAWED_OFF_PELLETS; i++) {
		float dispersion = (i + 1) / 2 * SAWED_OFF_DISPERSION * pow(-1, i % 2);
		projectile = new Projectile(owner->tag, damage, bulletLife, shotPoint.x,
			shotPoint.y + dispersion, game);
		engine->addActor(projectile);
		owner->projectiles->push_back(projectile);
		cpBodyApplyImpulseAtLocalPoint(projectile->body,
			cpv(orientation * projectileSpeed, dispersion),
			cpv(shotPoint.x, shotPoint.y));
	}
	sound->play();
}