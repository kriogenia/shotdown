#pragma once

#include "PlayerStateBase.h"

class DyingPlayerState :
    public PlayerStateBase
{
public:
    DyingPlayerState(Player* player);
    /* State */
    void enter() override;
    void tick() override;
	/* PlayerState */
	// Control
	inline void move(int direction) override {};
	inline void jump() override {};
	inline void dash() override {};
	inline void pressTrigger() override {};
	inline void releaseTrigger() override {};
	// Events
	inline void impacted(PlayerTag shooter, cpVect velocity) override {};
	inline void recoil(int force, cpVect point) override {};
};

