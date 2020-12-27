#include "Ak47.h"

Ak47::Ak47(Game* game) :
	Weapon("res/weapons/ak47.png", 30, 8, 30, 8, game)
{
	rarity = COMMON;
	loadedAmmo = AK47_CLIP_SIZE;
	unloadedAmmo = AK47_EXTRA_AMMO;
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

void Ak47::pressTrigger()
{
	cout << "Player pressing trigger" << endl;
	shooting = true;
}

void Ak47::releaseTrigger()
{
	cout << "Player released trigger" << endl;
	shooting = false;
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
	loadedAmmo--;
	cout << "AK-47 shooting" << endl;
	// Pushes back player
	owner->recoil(AK47_RECOIL);
}