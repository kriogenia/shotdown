#pragma once

#include "PlayerState.h"

#include "Player.h"
class Player;

/* Singleton */
class StateFactory
{
public:
    static StateFactory* getInstance();
    /* State generator */
    PlayerState* getState(ePlayerStates stateId, Player* player);

private:
    static StateFactory* instance;

    StateFactory();
};
