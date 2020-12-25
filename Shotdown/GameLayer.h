#pragma once

#include <chipmunk/chipmunk.h>

#include "Background.h"
#include "Layer.h"
#include "Player.h"
#include "Scenario.h"

class GameLayer :
    public Layer
{
public:
	GameLayer(Game* game);
	~GameLayer();
	/* Game cycle */
	void init() override;
	//void processControls() override;
	void update() override;
	void render() override;
	/* Input control */
	void keysToControl(SDL_Event event) override {};
	void padToControl(SDL_Event event) override {};
private:
	/* Showmatch */
	Player* player1;
	Player* player2;
	Background* background;
	queue<Scenario*> scenarios;
	/* Showmatch loading */
	void generateScenarios();
	void reset();
	void playNextScenario();
	/* Current scenario */
	Scenario* currentScenario;
	// vector<Projectile> projectiles;
	// vector<Spawner> spawners

};

