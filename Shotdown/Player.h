#pragma once

#include "Actor.h"

#include "PlayerState.h"
class PlayerState;

/* Attributes */
constexpr auto PLAYER_SIZE = 24;
constexpr auto PLAYER_SPEED = 3;
constexpr auto PLAYER_JUMP_HEIGHT = 32;
/* Physics */
constexpr auto PLAYER_BODY_WEIGHT = 3;
constexpr auto PLAYER_SHAPE_FRICTION = 0.8;

enum class PlayerTag {
    P1,
    P2
};

enum class ePlayerStates {
    IDLE,
    MOVING,
    JUMPING
};

class Player :
    public Actor
{
public:
    Player(PlayerTag tag, Game* game);
    ~Player();
    /* Game cycle */
    void update();
    /* Configuration */
    void init();
    void configureChipmunkSpace(cpSpace* chipSpace) override;
    /* Controls */
    void move(int direction);
    void jump();
    /* State */
    void setState(ePlayerStates id);
    /* Tag */
    PlayerTag tag;

private:
    /* State */
    PlayerState* state = nullptr;
    map<ePlayerStates, PlayerState*> states;
    void initStates();
    /* Movement */
    int controlX = 0;
};

