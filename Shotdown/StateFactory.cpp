#include "StateFactory.h"

#include "IdlePlayerState.h"
#include "JumpingPlayerState.h"
#include "MovingPlayerState.h"

StateFactory* StateFactory::instance = 0;

StateFactory* StateFactory::getInstance() {
    if (instance == 0)
        instance = new StateFactory;
    return instance;
}

StateFactory::StateFactory() {}

PlayerState* StateFactory::getState(ePlayerStates stateId, Player* player) {
    switch (stateId) {
    case ePlayerStates::IDLE:
        return new IdlePlayerState(player);
    case ePlayerStates::MOVING:
        return new MovingPlayerState(player);
    case ePlayerStates::JUMPING:
        return new JumpingPlayerState(player);
    default: 
        return nullptr;
    }
}
