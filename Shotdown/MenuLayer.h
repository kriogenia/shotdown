#pragma once

#include "Layer.h"
#include "Parallax.h"

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
    Actor* background = nullptr;
    Parallax* buildings = nullptr;

};

