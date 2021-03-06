#include "StateFactory.h"

#include "DashingPlayerState.h"
#include "DyingPlayerState.h"
#include "DoubleJumpingPlayerState.h"
#include "FallingPlayerState.h"
#include "IdlePlayerState.h"
#include "JumpingPlayerState.h"
#include "MovingPlayerState.h"
#include "SlidingPlayerState.h"

#include "EmptyWeaponState.h"
#include "LoadedWeaponState.h"
#include "ReloadingWeaponState.h"

StateFactory* StateFactory::instance = 0;

StateFactory* StateFactory::getInstance() 
{
    if (instance == 0)
        instance = new StateFactory;
    return instance;
}

StateFactory::StateFactory() 
{
}

PlayerState* StateFactory::getState(ePlayerStates stateId, Player* player) 
{
    switch (stateId) {
    case ePlayerStates::IDLE:
        return new IdlePlayerState(player);
    case ePlayerStates::MOVING:
        return new MovingPlayerState(player);
    case ePlayerStates::JUMPING:
        return new JumpingPlayerState(player);
    case ePlayerStates::DOUBLE_JUMPING:
        return new DoubleJumpingPlayerState(player);
    case ePlayerStates::FALLING:
        return new FallingPlayerState(player);
    case ePlayerStates::SLIDING:
        return new SlidingPlayerState(player);
    case ePlayerStates::DASHING:
        return new DashingPlayerState(player);
    case ePlayerStates::DYING:
        return new DyingPlayerState(player);
    default: 
        return nullptr;
    }
}

WeaponState* StateFactory::getState(eWeaponStates stateId, Weapon* weapon)
{
    switch (stateId) {
    case eWeaponStates::LOADED:
        return new LoadedWeaponState(weapon);
    case eWeaponStates::RELOADING:
        return new ReloadingWeaponState(weapon);
    case eWeaponStates::EMPTY:
        return new EmptyWeaponState(weapon);
    default:
        return nullptr;
    }
}