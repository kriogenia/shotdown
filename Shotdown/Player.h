#pragma once

#include "Actor.h"

#include "PlayerState.h"
class PlayerState;

/* Attributes */
constexpr auto PLAYER_SIZE = 24;
constexpr auto PLAYER_SPEED = 3 * TARGET_FPS;
constexpr auto PLAYER_JUMP_IMPULSE = 360 * TARGET_FPS;
//constexpr auto PLAYER_DOUBLE_JUMP_IMPULSE = 240 * TARGET_FPS;
/* Physics */
constexpr auto PLAYER_BODY_WEIGHT = 75;
constexpr auto PLAYER_SHAPE_FRICTION = 2;
constexpr auto PLAYER_MAX_FALL_SPEED = 10 * TARGET_FPS;

enum class PlayerTag {
    P1,
    P2
};

enum class PlayerOrientation {
    LEFT,
    RIGHT
};

enum class ePlayerStates {
    IDLE,
    MOVING,
    JUMPING,
    DOUBLE_JUMPING,
    FALLING,
    SLIDING,
    DASHING
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
    PlayerOrientation orientation;
    /* Events */
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
