#include "GameLayer.h"

#include "ChipmunkHelper.h"

GameLayer::GameLayer(Game* game) :
	Layer(game)
{
	background = new Background(game);
	currentScenario = nullptr;
	player1 = nullptr;
	player2 = nullptr;
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

void GameLayer::processControls()
{
	Layer::processControls();
	player1->move(controlMoveLeft_P1 + controlMoveRight_P1);
}

void GameLayer::update()
{
	// Physics update
	cpSpaceStep(currentScenario->chipSpace, .5);
	// Players update
	player1->update();
}

void GameLayer::render()
{
	background->render();
	currentScenario->render();
	player1->render();
	//player2->render();
}

void GameLayer::keysToControl(SDL_Event event) {
	/* Press */
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		switch (code) {
		case SDLK_ESCAPE:
			game->loopActive = false;
			break;
		case SDLK_1:
			game->scale();
			break;
		case SDLK_d:	// Right
			controlMoveRight_P1 = 1;
			break;
		case SDLK_a:	// Left
			controlMoveLeft_P1 = -1;
			break;
		case SDLK_w:	// Up
			//cout << "JUMP" << endl;
			player1->jump();
			break;
			/*
		case SDLK_s: // abajo
			controlMoveY1 = 1;
			break;
		case SDLK_SPACE: // dispara
			controlShoot1 = true;
			break;
			*/
		}
	}
	/* Release */
	if (event.type == SDL_KEYUP) {
		int code = event.key.keysym.sym;
		switch (code) {
		case SDLK_d:	// Right
			controlMoveRight_P1 = 0;
			break;
		case SDLK_a:	// Left
			controlMoveLeft_P1 = 0;
			break;
		}
	}
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

/* Clean previous state */
void GameLayer::reset()
{
	// Clear the scenario
	delete currentScenario;
	// Clear the entities
	player1->init();
	//player2->init();
	// projectiles.clear();
	// spawners.clear();
}

/* Finish the current scenario and starts a new one */
void GameLayer::playNextScenario()
{
	/* Clean state from previous scenario */
	reset();
	/* Load new scenario */
	currentScenario = scenarios.front();
	scenarios.pop();
	cout << "New match on scenario " << currentScenario->code << endl;
	/* Place the players and weapon spawners */
	auto spawnPoints = currentScenario->playerSpawns;
	player1->position = spawnPoints[0];
	player1->configureChipmunkSpace(currentScenario->chipSpace);
	//player2->position = spawnPoints[0];
	//player2->configureChipmunkSpace(currentScenario->chipSpace);
	// place Spawners
	/* Create the collision handlers */
	ChipmunkHelper::setHandlers(currentScenario->chipSpace);

}

