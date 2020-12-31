#pragma once

#include "AudioPlayer.h"
#include "Button.h"
#include "Layer.h"
#include "Parallax.h"

/* Buttons */
constexpr auto NEW_GAME_BUTTON_HEIGHT = 0.65 * HEIGHT;
/* Vehicles */
constexpr auto VEHICLE_SPAWN_TIME = 300;    // 5s
constexpr auto VEHICLE_SPEED = 6;

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
    /* Vehicles */
    Actor* vehicle = nullptr;
    vector<string> vehicles;
    void generateVehicle();
    int newVehicle = VEHICLE_SPAWN_TIME;
    /* Buttons */
    void selectButton(Button* button);
    Button* selected = nullptr;
    Button* newGameBtn = nullptr;
    /* Audio */
    AudioPlayer* audio = AudioPlayer::getInstance();

};

