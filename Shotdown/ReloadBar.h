#pragma once

#include "Player.h"

constexpr auto RELOAD_EXTRA_HEIGHT = 16;
constexpr auto RELOAD_EXTREME_WIDTH = 7;

class ReloadBar :
    public Actor
{
public:
    ReloadBar(Player* player, Game* game);
    /* Game cycle */
    void tick() override;
    void render(float rotation = 0.0) override;

private:
    /* Modules */
    Actor* arrow = nullptr;
    /* Refences */
    Player* player = nullptr;

};

