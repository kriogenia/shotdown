#include "Tec9.h"

Tec9::Tec9(Game* game) :
	AutomaticWeapon(TEC9_SPRITE, WEAPON_WIDTH, WEAPON_HEIGHT, game)
{
	/* Weapon */
	// Type
	rarity = static_cast<int>(WeaponRarity::COMMON);
	// Ammo
	clipSize = TEC9_CLIP_SIZE;
	loadedAmmo = TEC9_CLIP_SIZE;
	unloadedAmmo = TEC9_EXTRA_AMMO;
	// Cooldowns
	reloadTime = TEC9_RELOAD_TIME;
	shotCooldown = TEC9_WAIT_TIME;
	// Shooting
	recoil = TEC9_RECOIL_FORCE;
	shotPointOffset = { TEC9_SHOT_POINT_X , TEC9_SHOT_POINT_Y };
	// Projectile
	damage = TEC9_DAMAGE;
	projectileSpeed = TEC9_PROJECTILE_SPEED;
	recoilPerShot = TEC9_RECOIL_PER_SHOT;
	bulletLife = TEC9_PROJECTILE_LIFE;
	// Sound
	sound = new SoundEffect(TEC9_SOUND);
	/* AutomaticWeapon */
	anglePerShot = TEC9_ANGLE_PER_SHOT;
}

void Tec9::tick()
{
	furryCd--;
	AutomaticWeapon::tick();
}

void Tec9::shoot()
{
	/* Simulates semiauto firing */
	if (furryCd <= 0) {
		AutomaticWeapon::shoot();
		if (consecutiveShots >= TEC9_FURRY_SIZE) {
			consecutiveShots = 0;
			furryCd = TEC9_FURRY_CD;
		}
	}
}

Weapon* Tec9::clone(Player* owner)
{
	Weapon* clone = new Tec9(game);
	clone->owner = owner;
	clone->position = owner->position;
	clone->initStates();
	return clone;
}
