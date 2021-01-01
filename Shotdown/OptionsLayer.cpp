#include "OptionsLayer.h"

OptionsLayer::OptionsLayer(Game* game) :
	Layer(game)
{
	/* Background */
	background = new Actor(ActorType::BACKGROUND, "res/backgrounds/menu.png",
		WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, game);
	buildings = new Parallax("res/backgrounds/near-buildings.png", WIDTH, HEIGHT, game);
	/* Texts */
	texts.push_back(new Text("CUSTOM", WIDTH / 2, CUSTOM_HEIGHT, game));
	texts.push_back(new Text("1-HIT", TEXT_WIDTH_PLACE, ONE_HIT_HEIGHT, game));
	texts.push_back(new Text("ALL RANDOM", TEXT_WIDTH_PLACE, ALL_RANDOM_HEIGHT, game));
	texts.push_back(new Text("MATCHES", TEXT_WIDTH_PLACE, MATCHES_HEIGHT, game));
	for (auto const& text : texts) {
		text->setSize(TextSize::TITLE);
	}
}

void OptionsLayer::init()
{

}

void OptionsLayer::render()
{
	background->render();
	buildings->render();
	for (auto const& text : texts) {
		text->render();
	}
}

void OptionsLayer::keysToControl(SDL_Event event)
{

}

void OptionsLayer::mouseToControl(SDL_Event event)
{

}

void OptionsLayer::padToControl(SDL_Event event)
{

}
