#include "Nova.h"

Nova::Nova(Game* game) :
	ManualWeapon(NOVA_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::COMMON);
	// Ammo
	clipSize = NOVA_CLIP_SIZE;
	loadedAmmo = NOVA_CLIP_SIZE;
	unloadedAmmo = NOVA_EXTRA_AMMO;
	// Cooldowns
	reloadTime = NOVA_RELOAD_TIME;
	shotCooldown = NOVA_WAIT_TIME;
	// Shooting
	recoil = NOVA_RECOIL_FORCE;
	shotPointOffset = { NOVA_SHOT_POINT_X , NOVA_SHOT_POINT_Y };
	// Projectile
	damage = NOVA_DAMAGE;
	projectileSpeed = NOVA_PROJECTILE_SPEED;
	// Sound
	bulletLife = NOVA_PROJECTILE_LIFE;
	sound = new SoundEffect(NOVA_SOUND);
}

Weapon* Nova::clone(Player* owner)
{
	Weapon* clone = new Nova(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}

void Nova::shoot()
{
	Weapon::shoot();
	Projectile* projectile;
	float orientation = static_cast<float>(owner->orientation);
	// Fires projectiles
	for (int i = 0; i < NOVA_PELLETS; i++) {
		float dispersion = NOVA_DISPERSION - i * NOVA_DISPERSION * 2 / 3;
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