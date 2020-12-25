#include "ChipmunkHelper.h"

#include "Player.h"
#include "Tile.h"

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

void ChipmunkHelper::setHandlers(cpSpace* chipSpace)
{
	/* Player and tile collision */
	cpCollisionHandler* handler =
		cpSpaceAddCollisionHandler(
			chipSpace,
			static_cast<int>(ActorType::PLAYER),
			static_cast<int>(ActorType::TILE));
	handler->preSolveFunc = cpCollisionPreSolveFunc(collisionPlayerTile);

}