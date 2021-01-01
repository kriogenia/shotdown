#include "ResultLayer.h"

#include "AudioPlayer.h"

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
	score.clear();
}

void ResultLayer::tick()
{
	ticks++;
	if (ticks % SHOT_STEP == 0) {
		int index = ticks / SHOT_STEP - 1;
		if (index < game->score.size()) {
			addVictory(index);
		}
		else {
			addButton();
		}
	}
}

void ResultLayer::render()
{
	background->render();
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

}

void ResultLayer::padToControl(SDL_Event event)
{

}

void ResultLayer::addButton()
{
	if (button == nullptr) {
		// Placeholder
		float winnerX = (winsP1 > winsP2) ? P1_TEXT : P2_TEXT;
		winner = (new Text("WINNER", winnerX, VICTORY_HEIGHT, game))
			->setSize(TextSize::TITLE);
		button = new Button("res/hud/btn-new-game.png", WIDTH / 2,
			MAIN_GAME_BUTTON_HEIGHT, 300, 50, game);
		button->focus();
		AudioPlayer::getInstance()->play(AudioClips::CONFETTI);
	}
}

void ResultLayer::pressButton()
{
	if (button != nullptr) {
		game->changeLayer(Layers::START);
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
	AudioPlayer::getInstance()->play(AudioClips::SCORE);
}