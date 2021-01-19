#pragma once

#include <chipmunk/chipmunk.h>

#include "AudioPlayer.h"
#include "Background.h"
#include "Hud.h"
#include "Layer.h"
#include "Player.h"
#include "Projectile.h"
#include "Scenario.h"
#include "WeaponSpawner.h"

constexpr auto NUMBER_OF_SCENARIOS = 2;
constexpr auto JOYSTICK_SENSIBILITY = 10000;

class GameLayer :
    public Layer
{
public:
	GameLayer(Game* game);
	~GameLayer();
	/* Game cycle */
	void init() override;
	void processControls() override;
	void tick() override;
	void render() override;
	/* Input control */
	void keysToControl(SDL_Event event) override;
	inline void mouseToControl(SDL_Event event) override {};
	void padToControl(SDL_Event event) override;

private:
	/* References */
	Broadcaster* messager = Broadcaster::getInstance();
	ChipmunkHelper* engine = ChipmunkHelper::getInstance();
	Hud* hud = nullptr;
	/* Showmatch */
	Player* player1;
	Player* player2;
	Background* background;
	list<Actor*> projectiles;
	vector<WeaponSpawner*> spawners;
	queue<Scenario*> scenarios;
	/* Showmatch loading */
	void generateScenarios();
	void reset();
	void playNextScenario();
	/* Events */
	void pickWeapon(Player* player);
	/* Tick */
	void tickProjectiles();
	void victoryCheck();
	/* Current scenario */
	Scenario* currentScenario;
	/* Player1 Movement */
	int controlMoveLeft_P1 = 0;
	int controlMoveRight_P1 = 0;
	int controlMoveLeft_P2 = 0;
	int controlMoveRight_P2 = 0;

};

