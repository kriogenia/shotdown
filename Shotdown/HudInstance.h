#pragma once

#include "Pointer.h"
#include "WeaponDisplay.h"

constexpr auto SHOW_DURATION = 5 * TARGET_FPS;	// 5s

class HudInstance :
	public Hud
{
public:
	HudInstance(Player* player1, Player* player2, Game* game);
	~HudInstance();
	/* Game cycle */
	void tick() override;
	void render() override;
	/* Updates */
	void initShowdown() override;
	void updateWeapon(void* player) override;
	void showWinner(void* loser) override;

private:
	/* Modules */
	Text* title = nullptr;
	Pointer* pointerPlayer1 = nullptr;
	Pointer* pointerPlayer2 = nullptr;
	WeaponDisplay* weaponPlayer1 = nullptr;
	WeaponDisplay* weaponPlayer2 = nullptr;
	/* Counters */
	int show = 0;
	int round = 0;
	int loser = 0;

};

