#include "Game.h"
#include "GameLayer.h"

Game::Game() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error SDL_Init" << SDL_GetError() << endl;
	}
	cout << "Start Shotdown" << SDL_GetError() << endl;
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {
		cout << "Error Window y Renderer" << SDL_GetError() << endl;
	}
	SDL_SetWindowTitle(window, "Shotdown");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	/* Layer declaration */
	gameLayer = new GameLayer(this);
	layer = gameLayer;
	layer->init();

	loopActive = true; 
	loop();

	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
}

void Game::loop() {
	int initTick;
	int endTick;
	int differenceTick;
	while (loopActive) {
		initTick = SDL_GetTicks();
		/* Game cycle */
		layer->processControls();
		layer->update();
		layer->render();
		/* Rendering */
		SDL_RenderPresent(renderer);
		/* FPS check */
		endTick = SDL_GetTicks();
		differenceTick = endTick - initTick;
		//cout << differenceTick << " - " << 1000 / TARGET_FPS << endl;
		if (differenceTick < (1000 / TARGET_FPS)) {
			SDL_Delay((1000 / TARGET_FPS) - differenceTick);
		}
		else {
			cout << "LAG" << endl;
		}
	}
}

void Game::scale() {
	scaledToMax = !scaledToMax;

	if (scaledToMax) {
		SDL_DisplayMode PCdisplay;
		SDL_GetCurrentDisplayMode(0, &PCdisplay);
		float scaleX = (float)PCdisplay.w / (float)WIDTH;
		float scaleY = (float)PCdisplay.h / (float)HEIGHT;
		scaleLower = scaleX;
		if (scaleY < scaleX) {
			scaleLower = scaleY;
		}
		SDL_SetWindowSize(window, static_cast<int>(WIDTH * scaleLower), static_cast<int>(HEIGHT * scaleLower));
		SDL_RenderSetScale(renderer, scaleLower, scaleLower);
	}
	else {
		scaleLower = 1;
		SDL_SetWindowSize(window, WIDTH, HEIGHT);
		SDL_RenderSetScale(renderer, 1, 1);
	}

}

/* Manages the texture map */
SDL_Texture* Game::getTexture(string filename) {
	if (mapTextures.find(filename) == mapTextures.end()) {
		SDL_Surface* surface = IMG_Load(filename.c_str());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		mapTextures[filename] = texture;
	}
	return mapTextures[filename];
}
