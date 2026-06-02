#pragma once

#include "managers/audioManager.h"
#include "managers/tileManager.h"
#include "managers/mouseManager.h"
#include "creatures/creatureDef.h"

#include "raylib.h"

class Game {
public:
    Camera2D camera = {0};

    AudioManager audioManager;
    CreatureDef creatureDef;
    TileManager tileManager;
    MouseManager mouseManager;

    void ready();
    void update(float dt);
    void draw();
};