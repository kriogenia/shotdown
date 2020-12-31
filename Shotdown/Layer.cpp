#include "Layer.h"

Layer::Layer(Game* game) :
	game(game) {

}

void Layer::processControls()
{
	SDL_Event event;
	// Register input
	while (SDL_PollEvent(&event)) {
		// Close game
		if (event.type == SDL_QUIT) game->loopActive = false;
		// Input
		keysToControl(event);
		mouseToControl(event);
		padToControl(event);
	}
}