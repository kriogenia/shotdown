#pragma once

#include "Game.h"

constexpr auto TEXT_BLACK = 0;
constexpr auto TEXT_WHITE = 255;

enum class TextSize {
	TITLE,
	CAPTION
};

class Text
{
public:
	Text(string content, float x, float y, Game* game);
	/* Game cycle */
	void render();
	/* Configuration */
	Text* setSize(TextSize size);
	/* Attributes */
	string content = "";
	Point position = { 0, 0 };

private:
	/* Attributes */
	int outlineSize = 0;
	/* References */
	Game* game = nullptr;
	TTF_Font* bgFont = nullptr;
	TTF_Font* fgFont = nullptr;

};