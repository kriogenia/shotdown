#include "ChipmunkHelper.h"

#include "Player.h"
#include "Projectile.h"
#include "Tile.h"

ChipmunkHelper* ChipmunkHelper::instance = 0;

ChipmunkHelper* ChipmunkHelper::getInstance()
{
	if (instance == 0)
		instance = new ChipmunkHelper;
	return instance;
}

ChipmunkHelper::ChipmunkHelper()
{
	init();
}

void ChipmunkHelper::tick()
{
	cpSpaceStep(chipSpace, 1.0 / TARGET_FPS);
}

void ChipmunkHelper::init()
{
	// Create the physics engine of the scenario
	chipSpace = cpSpaceNew();
	cpSpaceSetGravity(chipSpace, cpv(0, GRAVITY));
}

/* Manage the collision between players and tiles */
cpBool collisionPlayerTile(cpArbiter* arb, cpSpace* space, void* dataPointerCollision)
{
	// Shape extraction
	cpShape* playerShape;
	cpShape* tileShape;
	cpArbiterGetShapes(arb, &playerShape, &tileShape);
	// Invoke collision method
	Player* player = (Player*)cpShapeGetUserData(playerShape);
	Tile* tile = (Tile*)cpShapeGetUserData(tileShape);
	player->collisioned(tile->position);

	return cpTrue;
}

/* Manage the collision between players and projectiles */
cpBool collisionPlayerProjectile(cpArbiter* arb, cpSpace* space, void* dataPointerCollision)
{
	// Shape extraction
	cpShape* playerShape;
	cpShape* projectileShape;
	cpArbiterGetShapes(arb, &playerShape, &projectileShape);
	// Invoke collision method
	Player* player = (Player*)cpShapeGetUserData(playerShape);
	Projectile* projectile = (Projectile*)cpShapeGetUserData(projectileShape);
	player->impacted(projectile->shooter);
	projectile->destroy();
	return cpTrue;
}

/* Creates the collision handlers */
void ChipmunkHelper::setHandlers()
{
	/* Player and tile collision */
	cpCollisionHandler* handlerPlayerTile =
		cpSpaceAddCollisionHandler(
			chipSpace,
			static_cast<int>(ActorType::PLAYER),
			static_cast<int>(ActorType::TILE));
	handlerPlayerTile->postSolveFunc = cpCollisionPostSolveFunc(collisionPlayerTile);
	/* Player and projectile collision */
	cpCollisionHandler* handlerPlayerProjectile =
		cpSpaceAddCollisionHandler(
			chipSpace,
			static_cast<int>(ActorType::PLAYER),
			static_cast<int>(ActorType::PROJECTILE));
	handlerPlayerProjectile->postSolveFunc = cpCollisionPostSolveFunc();

}

void ChipmunkHelper::addActor(Actor* actor)
{
	actor->configureChipmunkSpace(chipSpace);
}

void ChipmunkHelper::removeActor(Actor* actor)
{
	cpSpaceRemoveBody(chipSpace, actor->body);
	cpSpaceRemoveShape(chipSpace, actor->shape);
}

/* Sets gravity velocity to 0 */
void disableGravity(cpBody* body, cpVect gravity, cpFloat damping, cpFloat dt)
{
	cpBodyUpdateVelocity(body, cpv(gravity.x, 0), damping, dt);
}