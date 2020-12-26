#include "WeaponSpawner.h"

WeaponSpawner::WeaponSpawner(float x, float y, Game* game) :
	Actor(ActorType::SPAWNER, "res/weapons/spawner.png", x, y, 16, 32, game)
{
	position = {x + width/2, y + height/2};
	randomDisplay = new Actor(ActorType::SPAWNER, "res/weapons/random_spawner.png",
		position.x, position.y, 16, 32, game);
	getWeapon();
}

void WeaponSpawner::render()
{
	Actor::render();
	if (weapon != nullptr) {
		random ? randomDisplay->render() : weapon->render();
	}
}

/* Get a new weapon from the pool or goes ? */
void WeaponSpawner::getWeapon()
{
	random = (rand() % RANDOM_SPAWNER_RARITY == 0);
	WeaponFactory* factory = WeaponFactory::getInstance(game);
	weapon = random ? factory->getRandomWeapon() : factory->getWeapon();
	weapon->position = position;
	cout << "Spawned " << weapon->toString() << " at " << position.x << ", " << position.y << endl;
}