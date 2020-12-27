#pragma once

#include "Actor.h"

class Projectile : public Actor
{
public:
	Projectile(PlayerTag shooter, int lifeTime, float x, float y, Game* game);
	/* Actor */
	void tick() override;
	void render(float rotation = 0.0) override;
	/* Physics */
	void configureChipmunkSpace(cpSpace* chipSpace);
	/* Player */
	PlayerTag shooter;

private:
	/* Attributes */
	Point previousPosition;
	int lifeTime;

};

