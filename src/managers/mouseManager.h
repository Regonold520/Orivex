#pragma once

#include <vector>

#include "raylib.h"

class Game;

class MouseManager {
public:
    Game* game = nullptr;

    void update(float dt);
    void ready(Game* nGame);
    void draw();
};