#pragma once

#include "Actor.h"
#include "PlayerState.h"
#include "Weapon.h"
class Weapon;

/* Attributes */
constexpr auto PLAYER_SIZE = 24;
constexpr auto PLAYER_HP = 5;
constexpr auto PLAYER_SPEED = 3 * TARGET_FPS;
constexpr auto PLAYER_JUMP = 5 * TARGET_FPS;
// constexpr auto PLAYER_JUMP_IMPULSE = 360 * TARGET_FPS;
constexpr auto PLAYER_DASH_IMPULSE = 240 * TARGET_FPS;
constexpr auto PLAYER_DASH_DURATION = .5 * TARGET_FPS;   // .5s
constexpr auto SLIDING_SPEED = 2.5 * TARGET_FPS;
constexpr auto PLAYER_WALL_JUMP_X = 3 * TARGET_FPS;
constexpr auto PLAYER_WALL_JUMP_Y = 5 * TARGET_FPS;
//constexpr auto PLAYER_WALL_JUMP_IMPULSE_X = 180 * TARGET_FPS;
//constexpr auto PLAYER_WALL_JUMP_IMPULSE_Y = 360 * TARGET_FPS;
//constexpr auto PLAYER_DOUBLE_JUMP_IMPULSE = 240 * TARGET_FPS;
/* Cooldowns */
constexpr auto DASH_CD = 5 * TARGET_FPS; // 5s
/* Physics */
constexpr auto PLAYER_BODY_WEIGHT = 75;
constexpr auto PLAYER_SHAPE_FRICTION = 2;
constexpr auto PLAYER_MAX_FALL_SPEED = 10 * TARGET_FPS;
constexpr auto PLAYER_PUSH_DURATION = 10;

enum class Orientation {
    LEFT = -1,
    RIGHT = 1
};

class Player :
    public Actor
{
public:
    Player(PlayerTag tag, Game* game);
    ~Player();
    /* Game cycle */
    void tick() override;
    void render(float rotation = 0.0) override;
    /* Configuration */
    void init();
    void configureChipmunkSpace(cpSpace* chipSpace) override;
    /* Controls */
    void move(int direction);
    void jump();
    void dash();
    void pressTrigger();
    void releaseTrigger();
    /* Events */
    void collisioned(Point collisionedPosition);
    void impacted(PlayerTag shotOwner, cpVect velocity);
    void recoil(int force, cpVect point);
    /* State */
    PlayerState* prevState = nullptr;
    void setState(ePlayerStates id);
    Orientation orientation;
    int pushedBack = 0;
    /* Debug */
    string toString();
    /* Showdown */
    unsigned int victories = 0;
    /* Weapon */
    Weapon* weapon = nullptr;
    /* Tag */
    PlayerTag tag;
    /* Cooldowns */
    int dashCd = 0;
    /* Environment */
    list<Actor*>* projectiles;

private:
    /* State */
    PlayerState* state = nullptr;
    map<ePlayerStates, PlayerState*> states;
    void initStates();
    /* Attributes */
    int hp = PLAYER_HP;
};

