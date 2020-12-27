#pragma once

#include "Projectile.h"
#include "ChipmunkHelper.h"

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
	void render(float rotation = 0.0) override;
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
	/* Function */
	virtual void shoot();
	// WeaponState state;
	/* Engine */
	ChipmunkHelper* engine = ChipmunkHelper::getInstance();
	/* Properties */
	Point shotPoint = { 0, 0 };
	Point shotPointOffset = { 0, 0 };
	int recoil = 0;
	int shotCooldown = 0;
	//int reloadTime;
	/* Cooldowns */
	int remainingShotCd = 0;
};