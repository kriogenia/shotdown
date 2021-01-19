#pragma once

#include "Animation.h"
#include "Button.h"
#include "Layer.h"
#include "Parallax.h"

/* Buttons */
constexpr auto EXIT_BUTTON_HEIGHT = 0.1 * HEIGHT;
constexpr auto EXIT_BUTTON_WIDTH = 0.9 * WIDTH;
constexpr auto NEW_GAME_BUTTON_HEIGHT = 0.60 * HEIGHT;
constexpr auto CUSTOM_BUTTON_HEIGHT = 0.75 * HEIGHT;
/* Logo */
constexpr Point LOGO_POSITION = { 0.5 * WIDTH, 0.4 * HEIGHT};
/* Vehicles */
constexpr auto VEHICLE_SPAWN_TIME = 300;    // 5s
constexpr auto VEHICLE_SPEED = 6;

enum class Buttons {
    EXIT,
    NEW_GAME,
    CUSTOM
};

class MenuLayer :
    public Layer
{
public:
    MenuLayer(Game* game);
    /* Game cycle */
    void init() override;
    void tick() override;
    void render() override;
    /* Input control */
    void keysToControl(SDL_Event event) override;
    void mouseToControl(SDL_Event event) override;
    void padToControl(SDL_Event event) override;

private:
    /* Background */
    Actor* background = nullptr;
    Parallax* buildings = nullptr;
    /* Logo */
    Animation* logo = nullptr;
    /* Buttons */
    void selectButton(Buttons button);
    void changeButton(int direction);
    void pressButton();
    Buttons focused = Buttons::NEW_GAME;
    vector<Button*> buttons;
    /* Vehicles */
    Actor* vehicle = nullptr;
    vector<string> vehicles;
    void generateVehicle();
    int newVehicle = VEHICLE_SPAWN_TIME;

};

