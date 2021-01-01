#include "GameOptions.h"

GameOptions* GameOptions::instance = 0;

GameOptions* GameOptions::getInstance()
{
	if (instance == 0) {
		instance = new GameOptions;
	}
	return instance;
}

GameOptions::GameOptions()
{
	oneHit = false;
	allRandom = false;
	numberOfMatches = 5;
}