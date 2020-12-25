#include "GameLayer.h"

GameLayer::GameLayer(Game* game) :
	Layer(game)
{
	background = new Background(game);
	currentScenario = nullptr;
}

GameLayer::~GameLayer()
{
}

void GameLayer::init()
{
	// Generate the Players
	player1 = new Player(PlayerTag::P1, game);
	//player2 = new Player(PlayerTag::P2, game);
	// Generate the scenarios
	generateScenarios();
	// Load the first scenario
	playNextScenario();
}

void GameLayer::render()
{
	background->render();
	currentScenario->render();
	player1->render();
	//player2->render();
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
	player1->clear();
	player2->clear();
	// projectiles.clear();
	// spawners.clear();
	/* Load new scenario */
	currentScenario = scenarios.front();
	scenarios.pop();
	cout << "New match on scenario " << currentScenario->code << endl;
	/* Place the player and weapon spawners */
	auto spawnPoints = currentScenario->playerSpawns;
	player1->position = spawnPoints[0];
	// place Player2
	// place Spawners
}

