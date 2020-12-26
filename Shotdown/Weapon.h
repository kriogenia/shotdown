#pragma once

#include "Player.h"
class Player;

/* interface */
class Weapon :
	public Actor
{
public:
	Weapon(string filename, int width, int height, int fileWidth, int fileHeight, Game* game);
	/* Control */
	virtual void pressTrigger() = 0;
	virtual void releaseTrigger() = 0;
	/* Prototype */
	virtual Weapon* clone(Player* owner) = 0;
	/* Owner */
	Player* owner = nullptr;
	/* Attributes */
	int loadedAmmo = 0;
	int unloadedAmmo = 0;

protected:
	//WeaponState state;
	//int shotPoint;
	//int recoil; 
};