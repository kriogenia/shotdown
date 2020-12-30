#pragma once

#include "Actor.h"

class Projectile : public Actor
{
public:
	Projectile(PlayerTag shooter, int damage, int lifeTime, float x, float y, Game* game);
	/* Actor */
	void tick() override;
	void render(float rotation = 0.0) override;
	/* Physics */
	void configureChipmunkSpace(cpSpace* chipSpace);
	/* Player */
	PlayerTag shooter;
	/* Attributes */
	int damage = 0;

private:
	/* Attributes */
	Point previousPosition;
	int lifeTime;

};

