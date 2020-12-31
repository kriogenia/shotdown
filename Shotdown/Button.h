#pragma once

#include "Actor.h"

constexpr auto ARROW_WIDTH = 48;    //px
constexpr auto ARROW_HEIGHT = 84;   //px

class Button :
    public Actor
{
public:
    Button(string filename, float x, float y, int width, int height, Game* game);
    /* Game cycle */
    void render(float rotation = 0.0) override;
    /* Functionality */
    inline void focus() { focused = true; };
    inline void unfocus() { focused = false; };

private:
    /* Arrows */
    Actor* leftArrow = nullptr;
    Actor* rightArrow = nullptr;
    /* State */
    bool focused = false;

};

