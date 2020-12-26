#include "Weapon.h"

Weapon::Weapon(string filename, int width, int height, int fileWidth, int fileHeight, Game* game) :
	Actor(ActorType::WEAPON, filename, 0, 0, width, height, fileWidth, fileHeight, game)
{
}