#include "WeaponSpawner.h"

WeaponSpawner::WeaponSpawner(float x, float y, Game* game) :
	Actor(ActorType::SPAWNER, "res/weapons/spawner.png", x, y, 16, 32, game)
{
	position = {x + width/2, y + height/2};
	randomDisplay = new Actor(ActorType::SPAWNER, "res/weapons/random_spawner.png",
		position.x, position.y, 16, 32, game);
	getWeapon();
}

void WeaponSpawner::tick()
{
	if (weapon == nullptr) {
		cooldown--;
		if (cooldown <= 0) {
			getWeapon();
		}
	}
}

void WeaponSpawner::render(float rotation)
{
	Actor::render();
	if (weapon != nullptr) {
		random ? randomDisplay->render() : weapon->render(-90.0);
	}
}

bool WeaponSpawner::pickWeapon(Player* player)
{
	if (weapon != nullptr) {
		player->weapon = weapon->clone(player);
		weapon = nullptr;
		cooldown = SPAWNER_CD;
		return true;
	}
	return false;
}

/* Get a new weapon from the pool or goes ? */
void WeaponSpawner::getWeapon()
{
	random = (rand() % RANDOM_SPAWNER_RARITY == 0);
	//random = true;				// Debug
	WeaponFactory* factory = WeaponFactory::getInstance(game);
	weapon = random ? factory->getRandomWeapon() : factory->getWeapon();
	weapon->position = position;
	cout << "Spawned " << weapon->toString() << " at " << position.x << ", " << position.y << endl;
}