#include "MenuLayer.h"

MenuLayer::MenuLayer(Game* game) :
	Layer(game)
{
	/* Add vehicle filenames */
	vehicles.push_back("res/backgrounds/v-police.png");
	vehicles.push_back("res/backgrounds/v-red.png");
	vehicles.push_back("res/backgrounds/v-truck.png");
	vehicles.push_back("res/backgrounds/v-yellow.png");
	/* Background */
	background = new Actor(ActorType::BACKGROUND, "res/backgrounds/menu.png",
		WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, game);
	buildings = new Parallax("res/backgrounds/near-buildings.png", WIDTH, HEIGHT, game);
	/* Buttons */
	buttons.push_back(new Button("res/hud/exit.png", EXIT_BUTTON_WIDTH,
		EXIT_BUTTON_HEIGHT, 39, 42, game));
	buttons.push_back(new Button("res/hud/btn-new-game.png", WIDTH / 2,
		NEW_GAME_BUTTON_HEIGHT, 300, 50, game));
	buttons.push_back(new Button("res/hud/btn-new-game.png", WIDTH / 2,
		CUSTOM_BUTTON_HEIGHT, 300, 50, game));
	/* Init */
	init();
}

void MenuLayer::init()
{
	generateVehicle();
	audio->start();
	buttons[static_cast<int>(Buttons::NEW_GAME)]->focus();
	focused = Buttons::NEW_GAME;
}

void MenuLayer::tick()
{
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
		audio->play(AudioClips::PRESS);
		break;
	case Buttons::CUSTOM:
		game->changeLayer(Layers::OPTIONS);
		audio->play(AudioClips::PRESS);
		break;
	}
}