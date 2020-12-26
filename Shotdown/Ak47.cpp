#include "Ak47.h"

Ak47::Ak47(Game* game) :
	Weapon("res/weapons/ak47.png", 30, 8, 30, 8, game)
{
	loadedAmmo = AK47_CLIP_SIZE;
	unloadedAmmo = AK47_EXTRA_AMMO;
	rarity = COMMON;
}

void Ak47::tick()
{
	// Relocation
	if (owner != nullptr) {
		position = owner->position;
		// orientation
	}
	// Player is shooting
	if (shooting) {
		// Has ammo to shoot
		if (loadedAmmo > 0) {
			cout << "AK-47 shooting" << endl;
		}
		// No ammo left
		else {
			cout << "No ammo!" << endl;
			// TODO play empty clip sound
		}
	}
	// Player not shooting
	else {
		// No ammo left -> starts reload
		if (loadedAmmo <= 0) {
			cout << "Start reload" << endl;
		}
	}
}

void Ak47::pressTrigger()
{
	shooting = true;
}

void Ak47::releaseTrigger()
{
	shooting = false;
	rarity = COMMON;
}

Weapon* Ak47::clone(Player* owner)
{
	Weapon* clone = new Ak47(game);
	clone->owner = owner;
	clone->position = owner->position;
	return clone;
}