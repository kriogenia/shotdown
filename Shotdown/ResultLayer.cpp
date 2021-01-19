#include "ResultLayer.h"

ResultLayer::ResultLayer(Game* game) :
	Layer(game)
{
	/* Background */
	background = new Actor(ActorType::BACKGROUND, "res/backgrounds/result.png",
		WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, game);
	/* Text */
	textP1 = (new Text("P1", P1_TEXT, TITLES_HEIGHT, game))
		->setSize(TextSize::TITLE);
	textP2 = (new Text("P2", P2_TEXT, TITLES_HEIGHT, game))
		->setSize(TextSize::TITLE);
	init();
}

void ResultLayer::init()
{
	button = nullptr;
	winner = nullptr;
	focus = nullptr;
	score.clear();
	audio->end();
	ticks = 0;
	winsP1 = 0;
	winsP2 = 0;
}

void ResultLayer::tick()
{
	ticks++;
	if (ticks >= ANIMATION_START && ticks % SHOT_STEP == 0) {
		int index = (ticks - ANIMATION_START) / SHOT_STEP;
		if (index < game->score.size()) {
			addVictory(index);
		}
		else if(index > game->score.size()) {
			addButton();
		}
	}
}

void ResultLayer::render()
{
	background->render();
	if (focus != nullptr) {
		focus->render();
	}
	textP1->render();
	textP2->render();
	for (auto const& star : score) {
		star->render();
	}
	if (button != nullptr) {
		button->render();
	}
	if (winner != nullptr) {
		winner->render();
	}
}

void ResultLayer::keysToControl(SDL_Event event)
{
	/* Press */
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		switch (code) {
		case SDLK_RETURN:
		case SDLK_SPACE:	// Enter
			pressButton();
			break;
		}
	}
}

void ResultLayer::mouseToControl(SDL_Event event)
{
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (button->containsPoint({ motionX, motionY })) {
			pressButton();
		}
	}
}

void ResultLayer::padToControl(SDL_Event event)
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
		case SDL_CONTROLLER_BUTTON_A:			// A
			pressButton();
			break;
		}
	}
}

void ResultLayer::addButton()
{
	if (button == nullptr) {
		// Placeholder
		float winnerX = (winsP1 > winsP2) ? P1_TEXT : P2_TEXT;
		focus = new Actor(ActorType::HUD, "res/hud/focus-b.png", 
			winnerX, HEIGHT / 2, WIDTH / 2, HEIGHT, game);
		winner = (new Text("WINNER", winnerX, VICTORY_HEIGHT, game))
			->setSize(TextSize::TITLE);
		button = new Button("res/hud/btn-main-menu.png", WIDTH / 2,
			MAIN_GAME_BUTTON_HEIGHT, 300, 50, game);
		button->focus();
		audio->play(AudioClips::WINNER);
	}
}

void ResultLayer::pressButton()
{
	if (button != nullptr) {
		game->changeLayer(Layers::START);
		audio->play(AudioClips::PRESS);
	}
}

void ResultLayer::addVictory(int index)
{
	PlayerTag winner = game->score[index];
	float x, extraX;
	if (winner == PlayerTag::P1) {
		x = P1_TEXT;
		extraX = winsP1;
		winsP1++;
	}
	else {
		x = P2_TEXT;
		extraX = winsP2;
		winsP2++;
	}
	x = x - STARS_OFFSET + extraX * STARS_DISTANCE;
	score.push_back(new Actor(ActorType::HUD, "res/hud/star.png", x, STARS_HEIGHT,
		32, 31, game));
	audio->play(AudioClips::SCORE);
}