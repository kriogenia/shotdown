#include "WeaponSpawner.h"

WeaponSpawner::WeaponSpawner(float x, float y, Game* game) :
	Actor(ActorType::SPAWNER, "res/weapons/spawners.png", x, y, 16, 32, game)
{
	animation = new Animation("res/weapons/spawners.png", 96, 64, 4, 2, 8, 0, true, game);
	position = { x + width/2, y + height/2 };
	randomDisplay = new Actor(ActorType::SPAWNER, "res/weapons/random_spawner.png",
		position.x, position.y, 16, 32, game);
	getWeapon();
}

void WeaponSpawner::tick()
{
	if (weapon == nullptr) {
		cooldown--;
		// Inactive animation is progressive
		animation->currentFrame = 3 - (cooldown / (SPAWNER_CD / 4));
		animation->updateFrame();
		// Spawn a new weapon
		if (cooldown <= 0) {
			getWeapon();
		}
	}
	// Active animation is automatic
	else {
		animation->tick();
	}
}

void WeaponSpawner::render(float rotation)
{
	animation->render(position);
	if (weapon != nullptr) {
		random ? randomDisplay->render() : weapon->render(-90.0);
	}
}

bool WeaponSpawner::pickWeapon(Player* player)
{
	if (weapon != nullptr) {
		player->weapon = weapon->clone(player);
		// Goes inactive
		weapon = nullptr;
		cooldown = SPAWNER_CD;
		// Changes visuals
		animation->row = 1;
		animation->updateFrame();
		animation->reset();
		return true;
	}
	return false;
}

/* Get a new weapon from the pool or goes ? */
void WeaponSpawner::getWeapon()
{
	random = (game->options->allRandom) ? true : (rand() % RANDOM_SPAWNER_RARITY == 0);
	//random = true;				// Debug
	// Get and place weapon
	WeaponFactory* factory = WeaponFactory::getInstance(game);
	weapon = random ? factory->getRandomWeapon() : factory->getWeapon();
	weapon->position = { position.x - 3, position.y };
	// Change visuals
	animation->row = 0;
	animation->updateFrame();
	animation->reset();
	printf("Spawned %s at %.0f, %.0f\n", weapon->toString().c_str(), position.x, position.y);
}