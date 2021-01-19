#include "Animation.h"

Animation::Animation(string filename, float fileWidth, float fileHeight, int totalFrames, int totalRows, 
	int updateFrequence, int row, bool loop, Game* game) :
	fileWidth(fileWidth),
	fileHeight(fileHeight),
	frameWidth(fileWidth / totalFrames),
	frameHeight(fileHeight / totalRows),
	updateFrequence(updateFrequence),
	totalFrames(totalFrames),
	row(row),
	loop(loop),
	game(game),
	updateTime(0),
	currentFrame(0)
{
	// Load texture
	SDL_Surface* surface = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(game->renderer, surface);
	// Rectangle to show
	source.x = 0;
	source.y = row * frameHeight;
	source.w = frameWidth;
	source.h = frameHeight;
}

bool Animation::tick() 
{
	updateTime++;
	if (updateTime > updateFrequence) {
		updateTime = 0;
		currentFrame++;
		if (loop) {
			if (currentFrame >= totalFrames) {
				currentFrame = 0;
			}
		}
	}
	// Update frame rectangle
	source.x = currentFrame * frameWidth;
	return false;
}

void Animation::render(Point position, bool flip, float rotation) 
{
	// Place to render
	SDL_Rect destination;
	destination.x = position.x - frameWidth / 2;
	destination.y = position.y - frameHeight / 2;
	destination.w = frameWidth;
	destination.h = frameHeight;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, rotation, NULL, (flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE));
}

void Animation::reset()
{
	this->currentFrame = 0;
	this->updateTime = 0;
}