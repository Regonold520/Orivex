#pragma once

#include "audioManager.h"
#include "monsterDef.h"
#include "tileManager.h"

class Game {
public:
    AudioManager audioManager;
    MonsterDef monsterDef;
    TileManager tileManager;

    void ready();
    void update(float dt);
    void draw();
};