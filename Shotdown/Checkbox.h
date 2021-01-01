#pragma once

#include "Button.h"

class Checkbox :
    public Button
{
public:
    Checkbox(float x, float y, Game* game);
    /* Game cycle */
    void render(float rotation = 0.0) override;
    /* State */
    inline void press() { checked = !checked; }
    bool checked = false;

private:
    Actor* check = nullptr;

};

