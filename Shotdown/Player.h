#pragma once

#include "Actor.h"

constexpr auto PLAYER_SIZE = 24;
constexpr auto PLAYER_BODY_WEIGHT = 3;
constexpr auto PLAYER_SHAPE_FRICTION = 0.8;

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
    /* Game cycle */
    void update();
    /* Physics */
    void configureChipmunkSpace(cpSpace* chipSpace) override;
    /* Player reset */
    void clear();
    /* Tag */
    PlayerTag tag;

private:

};

