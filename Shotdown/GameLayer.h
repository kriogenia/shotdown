#pragma once

#include "Layer.h"
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
	void update() override {};
	void render() override;
	/* Input control */
	void keysToControl(SDL_Event event) override {};
	void padToControl(SDL_Event event) override {};
private:
	/* Showmatch */
	// Player player1
	// Player player2
	queue<Scenario*> scenarios;
	/* Showmatch loading */
	void generateScenarios();
	void playNextScenario();
	/* Current scenario */
	Scenario* currentScenario;
	// vector<Projectile> projectiles;
	// vector<Spawner> spawners

};

