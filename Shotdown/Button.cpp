#include "Button.h"

Button::Button(string filename, float x, float y, int width, int height, Game* game) :
	Actor(ActorType::HUD, filename, x, y, width, height, game)
{
	leftArrow = new Actor(ActorType::HUD, "res/hud/left-arrow.png",
		x - width / 2, y, ARROW_WIDTH, ARROW_HEIGHT, game);
	rightArrow = new Actor(ActorType::HUD, "res/hud/right-arrow.png",
		x + width / 2, y, ARROW_WIDTH, ARROW_HEIGHT, game);
}

void Button::render(float rotation)
{
	Actor::render();
	if (focused) {
		leftArrow->render();
		rightArrow->render();
	}
}