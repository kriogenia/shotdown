#pragma once

class GameOptions
{
public:
	static GameOptions* getInstance();
	/* Options */
	bool oneHit = false;
	bool allRandom = false;
	int numberOfMatches = 5;

private:
	static GameOptions* instance;

	GameOptions();
};

