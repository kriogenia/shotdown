#pragma once

#include "Actor.h"

class Parallax :
    public Actor
{
public:
    Parallax(string filename, int fileWidth, int fileHeight, Game* game);
};

