#include "ManualWeapon.h"
#include <SDL_mixer.h>

ManualWeapon::ManualWeapon(string filename, int width, int height, Game* game) :
	Weapon(filename, width, height, game)
{
}

void ManualWeapon::tick()
{
	Weapon::tick();
	state->tick();
}

void ManualWeapon::pressTrigger()
{
	state->shoot();
}

