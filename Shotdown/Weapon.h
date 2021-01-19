#pragma once

#include "Broadcaster.h"
#include "ChipmunkHelper.h"
#include "Projectile.h"
#include "SoundEffect.h"
#include "WeaponState.h"

#include "Player.h"
class Player;

enum class WeaponRarity {
	RARE = 1,
	UNCOMMON,
	COMMON
};

constexpr auto WEAPON_WIDTH = 96;
constexpr auto WEAPON_HEIGHT = 32;

/* interface */
class Weapon :
	public Actor
{
public:
	Weapon(string filename, int width, int height, Game* game);
	~Weapon();
	/* Actor */
	void tick() override;
	void render(float rotation = 0.0) override;
	/* Control */
	virtual void pressTrigger() = 0;
	virtual void releaseTrigger() = 0;
	virtual void shoot();
	/* State */
	void initStates();
	void setState(eWeaponStates stateId);
	/* Prototype */
	virtual Weapon* clone() = 0;
	virtual Weapon* clone(Player* owner) = 0;
	/* Debug */
	virtual string toString() = 0;
	/* References */
	Player* owner = nullptr;
	Broadcaster* messager = Broadcaster::getInstance();
	/* Attributes */
	int rarity = 0;
	string filename = "";
	/* Ammo */
	int loadedAmmo = 0;
	int unloadedAmmo = 0;
	int clipSize = 0;
	/* Reload */
	int reloadTimeLeft = 0;
	int reloadTime = 0;

protected:
	/* State */
	WeaponState* state = nullptr;
	map<eWeaponStates, WeaponState*> states;
	/* Engine */
	ChipmunkHelper* engine = ChipmunkHelper::getInstance();
	/* Sound */
	SoundEffect* sound = nullptr;
	/* Shooting */
	Point shotPoint = { 0, 0 };
	Point shotPointOffset = { 0, 0 };
	int recoil = 0;
	/* Cooldowns */
	int shotCooldown = 0;
	int remainingShotCd = 0;
	/* Projectiles */
	int damage = 0;
	int bulletLife = 0;
	float projectileSpeed = 0.0;
};