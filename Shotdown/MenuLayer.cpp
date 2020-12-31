#include "MenuLayer.h"

MenuLayer::MenuLayer(Game* game) :
	Layer(game)
{
	init();
}

void MenuLayer::init()
{
	background = new Actor(ActorType::BACKGROUND, "res/backgrounds/menu.png",
		WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, game);
	buildings = new Parallax("res/backgrounds/near-buildings.png", WIDTH, HEIGHT, game);

}

void MenuLayer::tick()
{

}

void MenuLayer::render()
{
	background->render();
	buildings->render();
}

void MenuLayer::keysToControl(SDL_Event event)
{

}

void MenuLayer::mouseToControl(SDL_Event event)
{

}

void MenuLayer::padToControl(SDL_Event event)
{

}