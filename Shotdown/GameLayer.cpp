#include "GameLayer.h"

GameLayer::GameLayer(Game* game) :
	Layer(game)
{
	currentScenario = nullptr;
}

GameLayer::~GameLayer()
{
}

void GameLayer::init()
{
	// Generate the Players
	// player1 = new Player
	// player2 = new Player
	// Generates the scenarios
	generateScenarios();
	// Loads the first scenario
	playNextScenario();
}

void GameLayer::render()
{
	currentScenario->render();
}

/* Generates a random pool of scenarios */
void GameLayer::generateScenarios()
{
	queue<int> scenarioCodes;
	// TODO Populate queue
	scenarioCodes.push(1);
	for (int code = scenarioCodes.front(); !scenarioCodes.empty(); scenarioCodes.pop()) {
		scenarios.push(new Scenario(code, game));
	}
}

/* Finish the current scenario and starts a new one */
void GameLayer::playNextScenario()
{
	/* Clean previous state */
	delete currentScenario;
	// player1.clear();
	// player2.clear();
	// projectiles.clear();
	// spawners.clear();
	/* Load new scenario */
	currentScenario = scenarios.front();
	scenarios.pop();
	cout << "New match on scenario " << currentScenario->code << endl;
	// place Player1
	// place Player2
	// place Spawners
}

