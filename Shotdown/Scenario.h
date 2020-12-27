#pragma once

#include "Game.h"
#include "Map.h"

class Scenario
{
public:
	Scenario(int code, Game* game);
	~Scenario();
	/* Game cycle */
	void render();
	/* Showmatch */
	void play();
	/* Spawn points */
	vector<Point> playerSpawns;
	vector<Point> wsSpawns;
	/* Properties */
	int code;
private:
	/* Initialization */
	void loadScenario(string filename);
	/* Scenario map */
	Map* scenario_map;
};
