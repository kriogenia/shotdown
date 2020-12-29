#pragma once

#include "Weapon.h"

class AutomaticWeapon :
    public Weapon
{
public:
    AutomaticWeapon(string filename, int width, int height, Game* game);
    /* Game cycle */
    void tick() override;
    void render(float rotation = 0.0) override;
    /* Control */
    void pressTrigger() override;
    void releaseTrigger() override;

protected:
    /* Function */
    void shoot() override;
    /* State */
    bool shooting = false;
    int consecutiveShots = 0;
    /* Properties */
    float recoilPerShot = 0.0;
    float anglePerShot = 0.0;
};
