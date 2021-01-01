#include "Game.h"

#include "GameLayer.h"
#include "MenuLayer.h"
#include "OptionsLayer.h"
#include "ResultLayer.h"

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

	/* Seed generation */
	srand((unsigned)time(NULL) % 1000);

	/* Fonts initilization */
	TTF_Init();
	fontTitle = TTF_OpenFont("res/Rubik-Black.ttf", 36);
	fontOutlineTitle = TTF_OpenFont("res/Rubik-Black.ttf", 36);
	TTF_SetFontOutline(fontOutlineTitle, TITLE_OUTLINE_SIZE);
	fontCaption = TTF_OpenFont("res/Rubik-Black.ttf", 18);
	fontOutlineSubtitle = TTF_OpenFont("res/Rubik-Black.ttf", 18);
	TTF_SetFontOutline(fontOutlineSubtitle, CAPTION_OUTLINE_SIZE);

	/* Layer initilization */
	layers.insert_or_assign(Layers::START, new MenuLayer(this));
	layers.insert_or_assign(Layers::OPTIONS, new OptionsLayer(this));
	layers.insert_or_assign(Layers::GAME, new GameLayer(this));
	layers.insert_or_assign(Layers::RESULT, new ResultLayer(this));
	layer = layers[Layers::START];
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
		layer->tick();
		layer->render();
		/* Rendering */
		SDL_RenderPresent(renderer);
		/* FPS check */
		endTick = SDL_GetTicks();
		differenceTick = endTick - initTick;
		if (differenceTick < (1000 / TARGET_FPS)) {
			SDL_Delay((1000 / TARGET_FPS) - differenceTick);
		}
		else {
			cout << "Low performance" << endl;
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

void Game::changeLayer(Layers layer)
{
	this->layer = layers[layer];
	this->layer->init();
}

