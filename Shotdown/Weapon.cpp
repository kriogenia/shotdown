#include "Weapon.h"

Weapon::Weapon(string filename, int width, int height, int fileWidth, int fileHeight, Game* game) :
	Actor(ActorType::WEAPON, filename, 0, 0, width, height, fileWidth, fileHeight, game)
{
}

void Weapon::tick()
{
	// Relocation
	if (owner != nullptr) {
		position = { owner->position.x, owner->position.y + 8 };
		// orientation
	}
}

void Weapon::render()
{
	// Orientation and rotation
	SDL_RendererFlip orientation = SDL_RendererFlip::SDL_FLIP_NONE;
	double rotation = 0;
	if (owner != nullptr) {
		if (owner->orientation == PlayerOrientation::LEFT) {
			orientation = SDL_FLIP_HORIZONTAL;
		}
	}
	else {
		rotation = -90;
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