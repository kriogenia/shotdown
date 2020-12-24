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
	/* Properties */
	int code;
private:
	void loadScenario(string filename);
	/* Scenario map */
	Map* scenario_map;
	/* Spawn points */
	vector<Point> playerSpawns;
	// weapon spawns
};
