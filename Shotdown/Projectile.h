#pragma once

#include "Actor.h"

class Projectile : public Actor
{
public:
	Projectile(PlayerTag shooter, int lifeTime, float x, float y, Game* game);
	/* Actor */
	void tick() override;
	void render() override;
	/* Physics */
	void configureChipmunkSpace(cpSpace* chipSpace);

private:
	/* Attributes */
	PlayerTag shooter;
	Point startingPoint;
	int lifeTime;
};

