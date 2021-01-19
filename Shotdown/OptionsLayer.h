#pragma once

#include "Checkbox.h"
#include "MenuLayer.h"
#include "Parallax.h"
#include "Text.h"

constexpr auto TEXT_WIDTH_PLACE = 0.4 * WIDTH;
constexpr auto EXIT_WIDTH_PLACE = 0.1 * WIDTH;
constexpr auto OPTIONS_WIDTH_PLACE = 0.75 * WIDTH;
constexpr auto EXIT_HEIGHT_PLACE = 0.9 * HEIGHT;
constexpr auto CUSTOM_HEIGHT = 0.2 * HEIGHT;
constexpr auto ONE_HIT_HEIGHT = 0.35 * HEIGHT;
constexpr auto ALL_RANDOM_HEIGHT = 0.5 * HEIGHT;
constexpr auto MATCHES_HEIGHT = 0.65 * HEIGHT;
constexpr auto RETURN_TO_MAIN_HEIGHT = 0.8 * HEIGHT;

enum class Options {
    BACK,
	ONE_HIT,
	ALL_RANDOM,
	MATCHES,
    RETURN
};

class OptionsLayer :
	public Layer
{
public:
    OptionsLayer(Game* game);
    /* Game cycle */
    void init() override;
    inline void tick() override { sleepJoystick--; };
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
    Options focused = Options::ONE_HIT;
    /* Buttons */
    vector<Button*> buttons;
    void selectButton(Options button);
    void changeButton(int direction);
    void pressButton();

    /***************
    * Button group *
    ****************/

    class ButtonGroup :
        public Button
    {
    public:
        ButtonGroup(float x, float y, Game* game);
        /* Game cycle */
        void render(float rotation = 0.0) override;
        /* Functionality */
        void press();
    
    private:
        vector<Button*> buttons;
        Actor* check = nullptr;
        int index = 1;

    };

};

