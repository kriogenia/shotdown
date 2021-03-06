#include "GameLayer.h"

#include "HudInstance.h"

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
	delete background;
	delete player1;
	delete player2;
	delete hud;
	projectiles.clear();
	spawners.clear();
}

void GameLayer::init()
{
	// Clean the score
	game->score.clear();
	// Generates the Players
	player1 = new Player(PlayerTag::P1, game);
	player1->projectiles = &projectiles;
	player2 = new Player(PlayerTag::P2, game);
	player2->projectiles = &projectiles;
	// Restarts their controls
	controlMoveRight_P1 = 0;
	controlMoveLeft_P1 = 0;
	controlMoveRight_P2 = 0;
	controlMoveLeft_P2 = 0;
	// Generates the HUD
	hud = new HudInstance(player1, player2, game);
	messager->hud = hud;
	// Generates the scenarios
	generateScenarios();
	// Loads the first scenario
	playNextScenario();
}

void GameLayer::processControls()
{
	Layer::processControls();
	player1->move(controlMoveLeft_P1 + controlMoveRight_P1);
	player2->move(controlMoveLeft_P2 + controlMoveRight_P2);
}

void GameLayer::tick()
{
	// Physics update
	engine->tick();
	// Players update
	player1->tick();
	player2->tick();
	// Projectiles update
	tickProjectiles();
	// Spawners update
	for (auto const& spawner : spawners) {
		spawner->tick();
	}
	// HUD update
	hud->tick();
	/* Victory check */
	victoryCheck();
}

void GameLayer::render()
{
	background->render();
	currentScenario->render();
	for (auto const& spawner : spawners) {
		spawner->render();
	}
	player1->render();
	player2->render();
	for (auto const& projectile : projectiles) {
		projectile->render();
	}
	hud->render();
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

void GameLayer::padToControl(SDL_Event event)
{
	/* Buttons */
	if (event.type == SDL_CONTROLLERBUTTONDOWN) {
		int code = event.cbutton.button;
		switch (code) {
		case SDL_CONTROLLER_BUTTON_BACK:
			game->loopActive = false;
			break;
		case SDL_CONTROLLER_BUTTON_Y:			// Y
			game->scale();
			break;
		case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:	// Right
			controlMoveRight_P2 = 1;
			break;
		case SDL_CONTROLLER_BUTTON_DPAD_LEFT:	// Left
			controlMoveLeft_P2 = -1;
			break;
		case SDL_CONTROLLER_BUTTON_A:			// A
			player2->jump();
			break;
		case SDL_CONTROLLER_BUTTON_X:			// X
			pickWeapon(player2);
			break;
		}
	}
	if (event.type == SDL_CONTROLLERAXISMOTION) {
		/* Joystick */
		if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) {
			if (event.caxis.value > JOYSTICK_SENSIBILITY) {
				controlMoveRight_P2 = 1;
			}
			else if (event.caxis.value < -JOYSTICK_SENSIBILITY) {
				controlMoveLeft_P2 = -1;
			}
			else {
				controlMoveRight_P2 = 0;
				controlMoveLeft_P2 = 0;
			}
		}
		/* Left trigger */
		else if (event.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT) {
			if (event.caxis.value > SDL_CONTROLLER_AXIS_MAX / 2) {
				player2->dash();
			}
		}
		/* Right trigger */
		else if (event.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT) {
			if (event.caxis.value > SDL_CONTROLLER_AXIS_MAX / 2) {
				player2->pressTrigger();
			}
			else {
				player2->releaseTrigger();
			}
		}
	}
}

/* Generates a random pool of scenarios */
void GameLayer::generateScenarios()
{
	vector<int> scenarioCodes;
	for (int i = 0; i < NUMBER_OF_SCENARIOS; i++) {
		scenarioCodes.push_back(i);
	}
	int numberOfShowdowns = (game->options->numberOfMatches);
	while (scenarios.size() != numberOfShowdowns) {
		int code = rand() % scenarioCodes.size(); 
		scenarios.push(new Scenario(scenarioCodes[code], game));
		scenarioCodes.erase(scenarioCodes.begin() + code);
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
	player2->init();
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
	player2->position = spawnPoints[1];
	engine->addActor(player2);
	auto spawnerLocations = currentScenario->wsSpawns;
	for (auto const& location : spawnerLocations) {
		spawners.push_back(new WeaponSpawner(location.x, location.y, game));
	}
	/* Starts the new background clip */
	messager->notify(Notifications::SHOWDOWN_INIT);
}

/* Launches player and spawner interaction event */
void GameLayer::pickWeapon(Player* player)
{
	for (auto const& spawner : spawners) {
		if (spawner->isOverlap(player)) {
			if (spawner->pickWeapon(player)) {
				printf("%s picked %s\n", player->toString().c_str(), player->weapon->toString().c_str());
				messager->notify(Notifications::PICK_WEAPON, player);
			}
			return;
		}
	}
}

/* Updates and deletes the projectiles */
void GameLayer::tickProjectiles()
{
	// Projectiles update
	vector<Actor*> projectilesToDelete;
	for (auto const& projectile : projectiles) {
		projectile->tick();
		if (projectile->pendingDestruction) {
			projectilesToDelete.push_back(projectile);
		}
	}
	// Projectiles deletion
	for (auto const& projectile : projectilesToDelete) {
		engine->removeActor(projectile);
		projectiles.remove(projectile);
	}
}

/* Checks showdown result and starts the next phase */
void GameLayer::victoryCheck()
{
	if (player1->pendingDestruction || player2->pendingDestruction) {
		if (player2->pendingDestruction) {
			player1->victories++;
			game->score.push_back(PlayerTag::P1);
			printf("%s wins this showdown. Starting next one...\n", player2->toString().c_str());
		}
		else {
			player2->victories++;
			game->score.push_back(PlayerTag::P2);
			printf("%s wins this showdown. Starting next one...\n", player2->toString().c_str());
		}
		if (scenarios.size() > 0) {
			playNextScenario();
		}
		else {
			game->changeLayer(Layers::RESULT);
		}
	}
}