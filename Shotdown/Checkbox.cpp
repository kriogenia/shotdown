#include "Checkbox.h"

Checkbox::Checkbox(float x, float y, Game* game) :
	Button("res/hud/checkbox.png", x, y, 39, 42, game)
{
	check = new Actor(ActorType::HUD, "res/hud/check.png", x, y, 39, 42, game);
}

void Checkbox::render(float rotation)
{
	Button::render();
	if (checked) {
		check->render();
	}
}