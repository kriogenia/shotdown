#include "ChipmunkHelper.h"
#include "Projectile.h"

Projectile::Projectile(PlayerTag shooter, int damage, int lifeTime, float x, float y, Game* game) :
	Actor(ActorType::PROJECTILE, "", x, y, 3, 3, game) 
{
	this->shooter = shooter;
	this->damage = damage;
	this->lifeTime = lifeTime;
	this->previousPosition = { x, y };
}

void Projectile::tick()
{
	// Update life time and destroy call
	lifeTime--;
	if (lifeTime <= 0) {
		this->destroy();
	}
	// Update position
	previousPosition = position;
	position.x = static_cast<float>(cpBodyGetPosition(body).x);
	position.y = static_cast<float>(cpBodyGetPosition(body).y);
}

void Projectile::render(float rotation)
{
	SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(game->renderer,	
		static_cast<int>(previousPosition.x),
		static_cast<int>(previousPosition.y),
		static_cast<int>(position.x),
		static_cast<int>(position.y));
}

void Projectile::configureChipmunkSpace(cpSpace* chipSpace) 
{
	/* Create the body */
	body = cpBodyNew(0.01, INFINITY);
	cpBodySetPosition(body, cpv(position.x, position.y));
	// Disable the gravity to this object
	cpBodySetVelocityUpdateFunc(body, disableGravity);
	cpSpaceAddBody(chipSpace, body);
	/* Create the shape */
	shape = cpBoxShapeNew(body, width, height, 0.0);
	// Collision type
	cpShapeSetCollisionType(shape, static_cast<int>(type));
	cpShapeSetElasticity(shape, 0); 
	cpShapeSetFriction(shape, 0.8); 
	// Collision filter
	cpShapeSetFilter(shape, cpShapeFilterNew(2, CP_ALL_CATEGORIES, CP_ALL_CATEGORIES));
	// Reference to the Actor into the Shape
	cpShapeSetUserData(shape, cpDataPointer(this));
	cpSpaceAddShape(chipSpace, shape);
}
