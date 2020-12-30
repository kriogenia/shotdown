#pragma once

#include "Actor.h"

class Bar :
    public Actor
{
public:
    Bar(string filename, float x, float y, int startingWidth, int height, Game * game);
    /* Game cycle */
    void render(float rotation = 0.0) override;
    /* Counters */
    int currentWidth;

};

