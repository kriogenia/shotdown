#pragma once

#include <chipmunk/chipmunk.h>

#include "Background.h"
#include "Layer.h"
#include "Player.h"
#include "Scenario.h"
#include "WeaponSpawner.h"

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
	void padToControl(SDL_Event event) override {};
private:
	/* Showmatch */
	Player* player1;
	Player* player2;
	Background* background;
	vector<WeaponSpawner*> spawners;
	queue<Scenario*> scenarios;
	/* Showmatch loading */
	void generateScenarios();
	void reset();
	void playNextScenario();
	/* Current scenario */
	Scenario* currentScenario;
	/* Player1 Movement */
	int controlMoveLeft_P1 = 0;
	int controlMoveRight_P1 = 0;
	int controlMoveLeft_P2 = 0;
	int controlMoveRight_P2 = 0;
	// vector<Projectile> projectiles;

};

