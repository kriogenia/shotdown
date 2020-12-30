#include "AutomaticWeapon.h"
#include <SDL_mixer.h>

AutomaticWeapon::AutomaticWeapon(string filename, int width, int height, Game* game) :
	Weapon(filename, width, height, game)
{
}

void AutomaticWeapon::tick()
{
	Weapon::tick();
	if (shooting) {
		state->shoot();
	}
	state->tick();
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
		Projectile* projectile = new Projectile(owner->tag, damage, bulletLife,
			shotPoint.x, shotPoint.y - weaponRecoil, game);
		// Adds projectile to game and engine
		engine->addActor(projectile);
		owner->projectiles->push_back(projectile);
		// Fires projectile
		cpBodyApplyImpulseAtLocalPoint(projectile->body,
			cpv(orientation * projectileSpeed, -weaponRecoil),
			cpv(shotPoint.x, shotPoint.y));
		sound->play();
		// Lowers accuracy
		consecutiveShots++;
	}
}