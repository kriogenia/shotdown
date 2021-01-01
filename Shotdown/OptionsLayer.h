#pragma once

#include "Layer.h"
#include "Parallax.h"
#include "Text.h"

constexpr auto TEXT_WIDTH_PLACE = 0.4 * WIDTH;
constexpr auto ONE_HIT_HEIGHT = 0.4 * HEIGHT;
constexpr auto ALL_RANDOM_HEIGHT = 0.5 * HEIGHT;
constexpr auto MATCHES_HEIGHT = 0.6 * HEIGHT;

class OptionsLayer :
    public Layer
{
public:
    OptionsLayer(Game* game);
	/* Game cycle */
	void init() override;
	inline void tick() override {};
	void render() override;
	/* Input control */
	void keysToControl(SDL_Event event) override;
	void mouseToControl(SDL_Event event) override;
	void padToControl(SDL_Event event) override;

private:
	/* Background */
	Actor* background = nullptr;
	Parallax* buildings = nullptr;
	/* Options */
	vector<Text*> texts;

};

