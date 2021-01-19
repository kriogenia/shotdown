#pragma once

#include "Button.h"
#include "Layer.h"
#include "Text.h"

constexpr auto P1_TEXT = 0.25 * WIDTH;
constexpr auto P2_TEXT = 0.75 * WIDTH;
constexpr auto STARS_OFFSET = 60;
constexpr auto STARS_DISTANCE = 24;
constexpr auto VICTORY_HEIGHT = 0.3 * HEIGHT;
constexpr auto TITLES_HEIGHT = 0.4 * HEIGHT;
constexpr auto STARS_HEIGHT = 0.5 * HEIGHT;
constexpr auto MAIN_GAME_BUTTON_HEIGHT = 0.75 * HEIGHT;
constexpr auto SHOT_STEP = 30;  // s
constexpr auto ANIMATION_START = 120;  // s

class ResultLayer :
    public Layer
{
public:
    ResultLayer(Game* game);
    /* Game cycle */
    void init() override;
    void tick() override;
    void render() override;
    /* Input control */
    void keysToControl(SDL_Event event) override;
    void mouseToControl(SDL_Event event) override;
    void padToControl(SDL_Event event) override;
    
private:
    /* Modules */
    Actor* background = nullptr;
    Text* textP1 = nullptr;
    Text* textP2 = nullptr;
    vector<Actor*> score;
    Text* winner = nullptr;
    Actor* focus = nullptr;
    Button* button = nullptr;
    /* Button */
    void addButton();
    void pressButton();
    /* Score */
    void addVictory(int index);
    int ticks = 0;
    int winsP1 = 0;
    int winsP2 = 0;

};

