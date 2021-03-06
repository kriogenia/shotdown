#include "ScoreBar.h"

ScoreBar::ScoreBar(string filename, float x, float y, int startingWidth, int height, Game* game) :
	Actor(ActorType::HUD, filename, x, y, startingWidth, height, game)
{
	this->currentWidth = startingWidth;
}

void ScoreBar::render(float rotation) {
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = currentWidth;	// width with the current max 
	source.h = fileHeight;		// texture.height;

	SDL_Rect destination;
	destination.x = static_cast<int>(position.x - currentWidth / 2);
	destination.y = static_cast<int>(position.y - height / 2);
	destination.w = currentWidth;
	destination.h = height;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, rotation, NULL, SDL_FLIP_NONE);
}