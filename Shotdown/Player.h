#pragma once

#include "Actor.h"

auto constexpr PLAYER_SIZE = 24;

enum class PlayerTag {
    P1,
    P2
};

class Player :
    public Actor
{
public:
    Player(PlayerTag tag, Game* game);
    ~Player();
    /* Player reset */
    void clear();
    /* Tag */
    PlayerTag tag;
};

