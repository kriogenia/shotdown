#include "MenuLayer.h"

MenuLayer::MenuLayer(Game* game) :
	Layer(game)
{
	/* Background */
	background = new Actor(ActorType::BACKGROUND, "res/backgrounds/menu.png",
		WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, game);
	buildings = new Parallax("res/backgrounds/near-buildings.png", WIDTH, HEIGHT, game);
	/* Logo */
	logo = new Animation("res/hud/logo-anim.png", 1200, 150, 4, 1, 12, 0, true, game);
	/* Add vehicle filenames */
	vehicles.clear();
	vehicles.push_back("res/backgrounds/v-police.png");
	vehicles.push_back("res/backgrounds/v-red.png");
	vehicles.push_back("res/backgrounds/v-truck.png");
	vehicles.push_back("res/backgrounds/v-yellow.png");
	/* Buttons */
	buttons.push_back(new Button("res/hud/exit.png", EXIT_BUTTON_WIDTH,
		EXIT_BUTTON_HEIGHT, 39, 42, game));
	buttons.push_back(new Button("res/hud/btn-new-game.png", WIDTH / 2,
		NEW_GAME_BUTTON_HEIGHT, 300, 50, game));
	buttons.push_back(new Button("res/hud/btn-custom.png", WIDTH / 2,
		CUSTOM_BUTTON_HEIGHT, 300, 50, game));
}

void MenuLayer::init()
{
	/* Init */
	generateVehicle();
	audio->start();
	for (auto const& button : buttons) {
		button->unfocus();
	}
	buttons[static_cast<int>(Buttons::NEW_GAME)]->focus();
	focused = Buttons::NEW_GAME;
}

void MenuLayer::tick()
{
	sleepJoystick--;
	logo->tick();
	vehicle->position.x -= VEHICLE_SPEED;
	newVehicle--;
	if (newVehicle <= 0) {
		newVehicle = VEHICLE_SPAWN_TIME;
		generateVehicle();
	}
}

void MenuLayer::render()
{
	background->render();
	vehicle->render();
	buildings->render();
	logo->render(LOGO_POSITION);
	for (auto const& button : buttons) {
		button->render();
	}
}

void MenuLayer::keysToControl(SDL_Event event)
{
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
		case SDLK_w:		// Up
			changeButton(-1);
			break;
		case SDLK_s:		// Down
			changeButton(1);
			break;
		case SDLK_RETURN:
		case SDLK_SPACE:	// Enter
			pressButton();
			break;
		}
	}
}

void MenuLayer::mouseToControl(SDL_Event event)
{
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;
	/* Hover */
	for (int i = 0; i < buttons.size(); i++) {
		Buttons tag = static_cast<Buttons>(i);
		if (focused != tag && buttons[i]->containsPoint({ motionX, motionY })) {
			selectButton(tag);
		}
	}
	/* Press */
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		pressButton();
	}
}

void MenuLayer::padToControl(SDL_Event event)
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
		case SDL_CONTROLLER_BUTTON_DPAD_UP:		// Up
			changeButton(-1);
			break;
		case SDL_CONTROLLER_BUTTON_DPAD_DOWN:	// Down
			changeButton(1);
			break;
		case SDL_CONTROLLER_BUTTON_A:			// A
			pressButton();
			break;
		}
	}
	/* Joystick */
	if (event.type == SDL_CONTROLLERAXISMOTION && sleepJoystick <= 0) {
		if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) {
			if (event.caxis.value > 30000) {
				changeButton(1);
				sleepJoystick = 30;
			}
			else if (event.caxis.value < -30000) {
				changeButton(-1);
				sleepJoystick = 30;
			}
		}
	}
}

void MenuLayer::generateVehicle()
{
	string file = vehicles[rand() % vehicles.size()];
	float y = rand() % 400 + 40;
	vehicle =  new Actor(ActorType::BACKGROUND, file, WIDTH + 61, y, 96, 61, game);
	newVehicle = VEHICLE_SPAWN_TIME;
}

void MenuLayer::selectButton(Buttons button)
{
	buttons[static_cast<int>(focused)]->unfocus();
	focused = button;
	buttons[static_cast<int>(focused)]->focus();
	audio->play(AudioClips::SELECT);
}

void MenuLayer::changeButton(int direction)
{
	int selected = static_cast<int>(focused) + direction;
	if (selected < 0) {
		selected = buttons.size() - 1;
	}
	if (selected >= buttons.size()) {
		selected = 0;
	}
	selectButton(static_cast<Buttons>(selected));
}

void MenuLayer::pressButton()
{
	switch (focused) {
	case Buttons::EXIT:
		game->loopActive = false;
		break;
	case Buttons::NEW_GAME:
		game->changeLayer(Layers::GAME);
		break;
	case Buttons::CUSTOM:
		game->changeLayer(Layers::OPTIONS);
		break;
	}
	audio->play(AudioClips::PRESS);
}