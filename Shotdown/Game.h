#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Layer.h"
class Layer;

using namespace std;

// Screen size
constexpr auto WIDTH = 720;
constexpr auto HEIGHT = 480;

class Game
{
public:
	Game();

	void loop();
	void scale();

	/* Rendering */
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool loopActive;
	float scaleLower = 1;

	/* Texture map */
	SDL_Texture* getTexture(string filename);

	/* Layers */
	Layer* layer;
	Layer* gameLayer;
	Layer* startLayer;
	Layer* finishLayer;


private:
	/* Texture map */
	map<string, SDL_Texture*> mapTextures;

	bool scaledToMax;
};
