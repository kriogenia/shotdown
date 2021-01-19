#include "Weapon.h"

#include "StateFactory.h"

Weapon::Weapon(string filename, int width, int height, Game* game) :
	Actor(ActorType::WEAPON, filename, 0, 0, width, height, game)
{
	this->filename = filename;
}

Weapon::~Weapon()
{
	delete sound;
	states.clear();
}

void Weapon::tick()
{
	// Relocation
	if (owner != nullptr) {
		position = owner->position;
		int orientation = static_cast<int>(owner->orientation);
		shotPoint = {
			position.x + orientation * shotPointOffset.x, 
			position.y + shotPointOffset.y
		};
	}
	remainingShotCd--;
}

void Weapon::render(float rotation)
{
	// Orientation and rotation
	SDL_RendererFlip orientation = SDL_RendererFlip::SDL_FLIP_NONE;
	if (owner != nullptr) {
		if (owner->orientation == Orientation::LEFT) {
			orientation = SDL_FLIP_HORIZONTAL;
		}
	}
	// Portion from source
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth;	// texture.width;
	source.h = fileHeight;	// texture.height;
	// Destination to draw
	SDL_Rect destination;
	destination.x = static_cast<int>(position.x - width / 2);
	destination.y = static_cast<int>(position.y - height / 2);
	destination.w = width;
	destination.h = height;
	// Render invocation
	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, rotation, NULL, orientation);
}

/* Shoots the weapon and apply its recoil */
void Weapon::shoot()
{
	loadedAmmo--;
	owner->recoil(recoil, cpv(shotPoint.x, shotPoint.y));
	remainingShotCd = shotCooldown;
	sound->play();
}

/* Populates the WeaponStates */
void Weapon::initStates()
{
	states.clear();
	StateFactory* factory = StateFactory::getInstance();
	states.insert_or_assign(eWeaponStates::LOADED, factory->getState(eWeaponStates::LOADED, this));
	states.insert_or_assign(eWeaponStates::RELOADING, factory->getState(eWeaponStates::RELOADING, this));
	states.insert_or_assign(eWeaponStates::EMPTY, factory->getState(eWeaponStates::EMPTY, this));
	state = states[eWeaponStates::LOADED];
}

void Weapon::setState(eWeaponStates stateId)
{
	state->exit();
	state = states[stateId];
	state->enter();
}