#pragma once

#include "Projectile.h"

#include "Player.h"
class Player;

enum WEAPON_RARITY {
	RARE = 1,
	UNCOMMON,
	COMMON
};

/* interface */
class Weapon :
	public Actor
{
public:
	Weapon(string filename, int width, int height, int fileWidth, int fileHeight, Game* game);
	/* Actor */
	void tick() override;
	void render() override;
	/* Control */
	virtual void pressTrigger() = 0;
	virtual void releaseTrigger() = 0;
	/* Prototype */
	virtual Weapon* clone() = 0;
	virtual Weapon* clone(Player* owner) = 0;
	/* Debug */
	virtual string toString() = 0;
	/* Owner */
	Player* owner = nullptr;
	/* Attributes */
	int rarity = 0;				
	int loadedAmmo = 0;
	int unloadedAmmo = 0;

protected:
	//WeaponState state;
	//int shotPoint;
	//int recoil; 
	//int reloadTime;
};