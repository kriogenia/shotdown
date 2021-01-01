#pragma once

#include "AudioPlayer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Layer.h"
class Layer;

using namespace std;

/* Game properties */
constexpr auto WIDTH = 720;
constexpr auto HEIGHT = 480;
constexpr auto TARGET_FPS = 60;
constexpr auto GRAVITY = 10 * TARGET_FPS;
/* Text */
constexpr auto TITLE_OUTLINE_SIZE = 2;
constexpr auto CAPTION_OUTLINE_SIZE = 1;

enum class Layers {
	START,
	GAME,
	RESULT
};

enum class ActorType {
	BACKGROUND,
	HUD,
	PLAYER,
	PROJECTILE,
	SPAWNER,
	TILE,
	WEAPON
};

enum class PlayerTag {
	P1 = 1,
	P2
};

class Game
{
public:
	Game();

	void loop();

	/* Rendering */
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool loopActive;
	float scaleLower = 1;
	void scale();

	/* Texture map */
	SDL_Texture* getTexture(string filename);

	/* Layers */
	Layer* layer;
	map<Layers, Layer*> layers;
	void changeLayer(Layers layer);

	/* Fonts */
	TTF_Font* fontTitle;
	TTF_Font* fontOutlineTitle;
	TTF_Font* fontCaption;
	TTF_Font* fontOutlineSubtitle;

	/* Score */
	vector<PlayerTag> score;

private:
	/* Texture map */
	map<string, SDL_Texture*> mapTextures;

	bool scaledToMax;
};

/* Coordinates object */
struct Point {
	float x;
	float y;
};