#pragma once

#include "Layer.h"
#include "Parallax.h"

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

};

