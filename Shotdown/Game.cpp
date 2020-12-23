#include "Game.h"

Game::Game() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error SDL_Init" << SDL_GetError() << endl;
	}
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {
		cout << "Error Window y Renderer" << SDL_GetError() << endl;
	}
	SDL_SetWindowTitle(window, "Juego de Naves");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	loopActive = true; 
	loop();
}

void Game::loop() {
	int initTick;
	int endTick;
	int differenceTick;
	while (loopActive) {
		initTick = SDL_GetTicks();

		// control
		// update
		// draw

		endTick = SDL_GetTicks();
		differenceTick = endTick - initTick;

		if (differenceTick < (1000 / 30)) {
			SDL_Delay((1000 / 30) - differenceTick);
		}
	}

}
