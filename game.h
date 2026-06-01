#pragma once

#include "audioManager.h"
#include "creatureDef.h"
#include "tileManager.h"
#include "mouseManager.h"

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