#pragma once

#include "Actor.h"

#include "PlayerState.h"
class PlayerState;

/* Attributes */
constexpr auto PLAYER_SIZE = 24;
constexpr auto PLAYER_SPEED = 3;
constexpr auto PLAYER_JUMP_HEIGHT = 32;
constexpr auto PLAYER_DOUBLE_JUMP_HEIGHT = 24;
/* Physics */
constexpr auto PLAYER_BODY_WEIGHT = 3;
constexpr auto PLAYER_SHAPE_FRICTION = 0.8;
constexpr auto PLAYER_MAX_FALL_SPEED = 15;

enum class PlayerTag {
    P1,
    P2
};

enum class ePlayerStates {
    IDLE,
    MOVING,
    JUMPING,
    DOUBLE_JUMPING,
    FALLING
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
    PlayerState* prevState = nullptr;
    void setState(ePlayerStates id);
    /* Interaction */
    void collisioned(Point collisionedPosition);
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

