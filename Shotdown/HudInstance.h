#pragma once

#include "InfoDisplay.h"
#include "Pointer.h"
#include "ReloadBar.h"

constexpr auto SHOW_DURATION = 3 * TARGET_FPS;	// 3s

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
	void switchReload(void* player, bool state) override;
	void updateWeapon(void* player) override;
	void showWinner(void* loser) override;

private:
	/* Modules */
	Text* title = nullptr;
	Pointer* pointerPlayer1 = nullptr;
	Pointer* pointerPlayer2 = nullptr;
	InfoDisplay* infoPlayer1 = nullptr;
	InfoDisplay* infoPlayer2 = nullptr;
	ReloadBar* reloadPlayer1 = nullptr;
	ReloadBar* reloadPlayer2 = nullptr;
	/* Flags */
	int show = 0;
	int round = 0;
	int loser = 0;
	bool p1_reloading = false;
	bool p2_reloading = false;

};

