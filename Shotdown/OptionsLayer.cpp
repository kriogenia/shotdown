#include "OptionsLayer.h"

OptionsLayer::OptionsLayer(Game* game) :
	Layer(game)
{
	/* Background */
	background = new Actor(ActorType::BACKGROUND, "res/backgrounds/menu.png",
		WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, game);
	buildings = new Parallax("res/backgrounds/near-buildings.png", WIDTH, HEIGHT, game);
	/* Texts */
	texts.clear();
	texts.push_back(new Text("CUSTOM", WIDTH / 2, CUSTOM_HEIGHT, game));
	texts.push_back(new Text("1-HIT", TEXT_WIDTH_PLACE, ONE_HIT_HEIGHT, game));
	texts.push_back(new Text("ALL RANDOM", TEXT_WIDTH_PLACE, ALL_RANDOM_HEIGHT, game));
	texts.push_back(new Text("MATCHES", TEXT_WIDTH_PLACE, MATCHES_HEIGHT, game));
	for (auto const& text : texts) {
		text->setSize(TextSize::TITLE);
	}
	/* Options */
	buttons.clear();
	buttons.push_back(new Button("res/hud/exit.png", EXIT_WIDTH_PLACE,
		EXIT_HEIGHT_PLACE, 39, 42, game));
	buttons.push_back(new Checkbox(OPTIONS_WIDTH_PLACE, ONE_HIT_HEIGHT, game));
	buttons.push_back(new Checkbox(OPTIONS_WIDTH_PLACE, ALL_RANDOM_HEIGHT, game));
	buttons.push_back(new ButtonGroup(OPTIONS_WIDTH_PLACE, MATCHES_HEIGHT, game));
	buttons.push_back(new Button("res/hud/btn-new-game.png", WIDTH / 2,
		RETURN_TO_MAIN_HEIGHT, 300, 50, game));
}

void OptionsLayer::init()
{
	/* Init */
	((Checkbox*)buttons[static_cast<int>(Options::ONE_HIT)])->checked = game->options->oneHit;
	((Checkbox*)buttons[static_cast<int>(Options::ALL_RANDOM)])->checked = game->options->allRandom;
	for (auto const& button : buttons) {
		button->unfocus();
	}
	buttons[static_cast<int>(Options::ONE_HIT)]->focus();
	focused = Options::ONE_HIT;
}

void OptionsLayer::render()
{
	background->render();
	buildings->render();
	for (auto const& text : texts) {
		text->render();
	}
	for (auto const& button : buttons) {
		button->render();
	}
}

void OptionsLayer::keysToControl(SDL_Event event)
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

void OptionsLayer::mouseToControl(SDL_Event event)
{
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;
	/* Hover */
	for (int i = 0; i < buttons.size(); i++) {
		Options tag = static_cast<Options>(i);
		if (focused != tag && buttons[i]->containsPoint({ motionX, motionY })) {
			selectButton(tag);
		}
	}
	/* Press */
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		pressButton();
	}

}

void OptionsLayer::padToControl(SDL_Event event)
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
		case SDL_CONTROLLER_BUTTON_B:			// B
			game->changeLayer(Layers::START);
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

void OptionsLayer::selectButton(Options button)
{
	buttons[static_cast<int>(focused)]->unfocus();
	focused = button;
	buttons[static_cast<int>(focused)]->focus();
	audio->play(AudioClips::SELECT);
}

void OptionsLayer::changeButton(int direction)
{
	int selected = static_cast<int>(focused) + direction;
	if (selected < 0) {
		selected = buttons.size() - 1;
	}
	if (selected >= buttons.size()) {
		selected = 0;
	}
	selectButton(static_cast<Options>(selected));
}

void OptionsLayer::pressButton()
{
	Checkbox* pressed;
	switch (focused) {
	case Options::BACK:
		game->changeLayer(Layers::START);
		break;
	case Options::ONE_HIT:
		pressed = (Checkbox*)buttons[static_cast<int>(Options::ONE_HIT)];
		pressed->press();
		game->options->oneHit = pressed->checked;
		break;
	case Options::ALL_RANDOM:
		pressed = (Checkbox*)buttons[static_cast<int>(Options::ALL_RANDOM)];
		pressed->press();
		game->options->allRandom = pressed->checked;
		break;
	case Options::MATCHES:
		((ButtonGroup*)buttons[static_cast<int>(Options::MATCHES)])->press();
		break;
	case Options::RETURN:
		game->changeLayer(Layers::GAME);
		break;
	}
	audio->play(AudioClips::PRESS);
}

/***************
* Button group *
****************/

OptionsLayer::ButtonGroup::ButtonGroup(float x, float y, Game* game)
	: Button("", x, y, 39 * 3, 42, game)
{
	buttons.push_back(new Button("res/hud/checkbox.png", x - 39, y, 39, 42, game));
	buttons.push_back(new Button("res/hud/checkbox.png", x, y, 39, 42, game));
	buttons.push_back(new Button("res/hud/checkbox.png", x + 39, y, 39, 42, game));
	texts.push_back((new Text("3", x - 39, y, game))->setSize(TextSize::CAPTION));
	texts.push_back((new Text("5", x, y, game))->setSize(TextSize::CAPTION));
	texts.push_back((new Text("7", x + 39, y, game))->setSize(TextSize::CAPTION));
	check = new Actor(ActorType::HUD, "res/hud/check.png", x, y, 39, 42, game);
}

void OptionsLayer::ButtonGroup::render(float rotation)
{
	for (auto const button : buttons) {
		button->render();
	}
	check->render();
	for (auto const text : texts) {
		text->render();
	}
	Button::render();
}

void OptionsLayer::ButtonGroup::press()
{
	// Change selected
	index++;
	if (index >= buttons.size()) {
		index = 0;
	}
	check->position = buttons[index]->position;
	// Change options
	if (index == 0) {
		game->options->numberOfMatches = 3;
	}
	else if (index == 1) {
		game->options->numberOfMatches = 5;
	}
	else {
		game->options->numberOfMatches = 7;
	}
}