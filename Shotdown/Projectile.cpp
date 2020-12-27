#include "Projectile.h"

Projectile::Projectile(PlayerTag shooter, int lifeTime, float x, float y, Game* game) :
	Actor(ActorType::PROJECTILE, "", x, y, 1, 1, game) 
{
	this->shooter = shooter;
	this->lifeTime = lifeTime;
	this->startingPoint = { x, y };
}

void Projectile::tick() 
{
	// Update life time and destroy call
	lifeTime--;
	if (lifeTime <= 0) {
		this->destroy();
	}
	// Update position
	position = { cpBodyGetPosition(body).x, cpBodyGetPosition(body).y };
}

void Projectile::render()
{
	SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(game->renderer,	startingPoint.x, startingPoint.y, position.x, position.y);
}

void Projectile::configureChipmunkSpace(cpSpace* chipSpace) 
{
	// Create the body
	body = cpBodyNew(1, INFINITY);
	cpBodySetPosition(body, cpv(position.x, position.y));
	cpSpaceAddBody(chipSpace, body);
	// Create the shape
	shape = cpBoxShapeNew(body, width, height, 0.0);
	cpShapeSetElasticity(shape, 0); 
	cpShapeSetFriction(shape, 0.8); 
	cpSpaceAddShape(chipSpace, shape);
	// Reference to the Actor into the Shape
	cpShapeSetUserData(shape, cpDataPointer(this));
}
