#include "Ak47.h"

Ak47::Ak47(Game* game) :
	Weapon("res/weapons/ak47.png", 30, 8, 30, 8, game)
{
	rarity = COMMON;
	loadedAmmo = AK47_CLIP_SIZE;
	unloadedAmmo = AK47_EXTRA_AMMO;
	shotPointOffset = { AK47_SHOT_POINT_X , AK47_SHOT_POINT_Y };
	recoil = AK47_RECOIL_FORCE;
}

void Ak47::tick()
{
	Weapon::tick();
	// Player is shooting
	if (shooting) {
		// Has ammo to shoot
		if (loadedAmmo > 0) {
			shoot();
		}
		// No ammo left
		else {
			//cout << "No ammo!" << endl;
			// TODO play empty clip sound
		}
	}
	// Player not shooting
	else {
		// No ammo left -> starts reload
		if (loadedAmmo <= 0) {
			//cout << "Start reload" << endl;
		}
	}
}

void Ak47::render(float rotation)
{
	Weapon::render(static_cast<float>(consecutiveShots));
}

void Ak47::pressTrigger()
{
	shooting = true;
}

void Ak47::releaseTrigger()
{
	shooting = false;
	consecutiveShots = 0;
}

Weapon* Ak47::clone(Player* owner)
{
	Weapon* clone = new Ak47(game);
	clone->owner = owner;
	clone->position = owner->position;
	return clone;
}

void Ak47::shoot()
{
	Weapon::shoot();
	float orientation = static_cast<float>(owner->orientation);
	// Create projectile
	float weaponRecoil = static_cast<float>(consecutiveShots * AK47_RECOIL_PER_SHOT);
	Projectile* projectile = new Projectile(owner->tag, AK47_BULLET_LIFE, 
		shotPoint.x, shotPoint.y - weaponRecoil, game);
	// Add projectile to game and engine
	engine->addActor(projectile);
	owner->projectiles->push_back(projectile);
	// Fires projectile
	cpBodyApplyImpulseAtLocalPoint(projectile->body, 
		cpv(orientation * 5.0, -weaponRecoil),
		cpv(shotPoint.x, shotPoint.y));
	// Lowers accuracy
	consecutiveShots++;
}