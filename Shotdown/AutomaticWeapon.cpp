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
	if (owner != nullptr) {
		Weapon::render(consecutiveShots * anglePerShot * -static_cast<float>(owner->orientation));
	}
	else {
		Weapon::render(rotation);
	}
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
	if (remainingShotCd <= 0) {
		Weapon::shoot();
		float orientation = static_cast<float>(owner->orientation);
		// Creates projectile
		float weaponRecoil = static_cast<float>(consecutiveShots * recoilPerShot);
		Projectile* projectile = new Projectile(owner->tag, bulletLife,
			shotPoint.x, shotPoint.y - weaponRecoil, game);
		// Adds projectile to game and engine
		engine->addActor(projectile);
		owner->projectiles->push_back(projectile);
		// Fires projectile
		cpBodyApplyImpulseAtLocalPoint(projectile->body,
			cpv(orientation * projectileSpeed, -weaponRecoil),
			cpv(shotPoint.x, shotPoint.y));
		// Lowers accuracy and starts cd
		consecutiveShots++;
		remainingShotCd = shotCooldown;
	}
}