#include "AutomaticWeapon.h"

AutomaticWeapon::AutomaticWeapon(string filename, int width, int height, int fileWidth, int fileHeight, Game* game) :
	Weapon(filename, width, height, fileWidth, fileHeight, game)
{
}

void AutomaticWeapon::tick()
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

void AutomaticWeapon::render(float rotation)
{
	Weapon::render(static_cast<float>(consecutiveShots * 2));
}

void AutomaticWeapon::pressTrigger()
{
	shooting = true;
}

void AutomaticWeapon::releaseTrigger()
{
	shooting = false;
	consecutiveShots = 0;
}

void AutomaticWeapon::shoot()
{
	Weapon::shoot();
	float orientation = static_cast<float>(owner->orientation);
	// Create projectile
	float weaponRecoil = static_cast<float>(consecutiveShots * recoilPerShot);
	Projectile* projectile = new Projectile(owner->tag, bulletLife,
		shotPoint.x, shotPoint.y - weaponRecoil, game);
	// Add projectile to game and engine
	engine->addActor(projectile);
	owner->projectiles->push_back(projectile);
	// Fires projectile
	cpBodyApplyImpulseAtLocalPoint(projectile->body,
		cpv(orientation * projectileSpeed, -weaponRecoil),
		cpv(shotPoint.x, shotPoint.y));
	// Lowers accuracy
	consecutiveShots++;
}