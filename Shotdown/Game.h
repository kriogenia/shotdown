#pragma once


#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

// Valores generales
#define WIDTH 720
#define HEIGHT 720

class Game
{
public:
	Game();
	void loop();
	SDL_Window* window; // ventana
	SDL_Renderer* renderer; // renderizador
	bool loopActive; // Juego activo
};
