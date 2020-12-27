#include "GameLayer.h"

#include "ChipmunkHelper.h"

GameLayer::GameLayer(Game* game) :
	Layer(game)
{
	engine = ChipmunkHelper::getInstance();
	background = new Background(game);
	currentScenario = nullptr;
	player1 = nullptr;
	player2 = nullptr;
}

GameLayer::~GameLayer()
{
	delete background;
	delete player1;
	delete player2;
	projectiles.clear();
	spawners.clear();
}

void GameLayer::init()
{
	// Generates the Players
	player1 = new Player(PlayerTag::P1, game);
	player1->projectiles = &projectiles;
	//player2 = new Player(PlayerTag::P2, game);
	//player2->projectiles = &projectiles;
	// Generates the scenarios
	generateScenarios();
	// Loads the first scenario
	playNextScenario();
}

void GameLayer::processControls()
{
	Layer::processControls();
	player1->move(controlMoveLeft_P1 + controlMoveRight_P1);
	//player2->move(controlMoveLeft_P2 + controlMoveRight_P2);
}

void GameLayer::tick()
{
	// Physics update
	engine->tick();
	// Players update
	player1->tick();
	//player2->tick();
	// Projectiles update
	vector<Actor*> projectilesToDelete;
	for (auto const& projectile : projectiles) {
		projectile->tick();
		if (projectile->pendingDestruction) {
			projectilesToDelete.push_back(projectile);
		}
	}
	// Spawners update
	for (auto const& spawner : spawners) {
		spawner->tick();
	}
	/* Actors deletion */
	// Projectiles
	for (auto const& projectile : projectilesToDelete) {
		engine->removeActor(projectile);
		projectiles.remove(projectile);
	}
}

void GameLayer::render()
{
	background->render();
	currentScenario->render();
	for (auto const& spawner : spawners) {
		spawner->render();
	}
	player1->render();
	//player2->render();
	for (auto const& projectile : projectiles) {
		projectile->render();
	}
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
		case SDLK_d:		// Right
			controlMoveRight_P1 = 1;
			break;
		case SDLK_a:		// Left
			controlMoveLeft_P1 = -1;
			break;
		case SDLK_w:		// Jump
			//cout << "JUMP" << endl;
			player1->jump();
			break;
		case SDLK_LSHIFT:	// Dash
			player1->dash();
			break;
		case SDLK_e:		// Pick weapon
			pickWeapon(player1);
			break;
		case SDLK_SPACE:	// Shoot
			player1->pressTrigger();
			break;
		}
	}
	/* Release */
	if (event.type == SDL_KEYUP) {
		int code = event.key.keysym.sym;
		switch (code) {
		case SDLK_d:		// Right
			controlMoveRight_P1 = 0;
			break;
		case SDLK_a:		// Left
			controlMoveLeft_P1 = 0;
			break;
		case SDLK_SPACE:	// Stop Shooting
			player1->releaseTrigger();
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

/* Cleans previous state */
void GameLayer::reset()
{
	// Clears the scenario
	delete currentScenario;
	// Starts and configures a new space
	engine->init();
	engine->setHandlers();
	// Clears the entities
	player1->init();
	//player2->init();
	projectiles.clear();
	spawners.clear();
}

/* Finishes the current scenario and starts a new one */
void GameLayer::playNextScenario()
{
	/* Cleans state from previous scenario */
	reset();
	/* Loads new scenario */
	currentScenario = scenarios.front();
	scenarios.pop();
	currentScenario->play();
	/* Places the players and weapon spawners */
	auto spawnPoints = currentScenario->playerSpawns;
	player1->position = spawnPoints[0];
	engine->addActor(player1);
	//player2->position = spawnPoints[0];
	//engine->addActor(player2);
	/* Creates spawners on the specified locations */
	auto spawnerLocations = currentScenario->wsSpawns;
	for (auto const& location : spawnerLocations) {
		spawners.push_back(new WeaponSpawner(location.x, location.y, game));
	}
}

/* Launches player and spawner interaction event */
void GameLayer::pickWeapon(Player* player)
{
	for (auto const& spawner : spawners) {
		if (spawner->isOverlap(player)) {
			spawner->pickWeapon(player);
			return;
		}
	}
}
