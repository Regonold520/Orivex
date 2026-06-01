#pragma once

#include <vector>

#include "raylib.h"

class Game;

class TileManager {
public:
    Game* game = nullptr;

    struct Tile {
        Vector2 pos = {0,0};
        std::vector<Vector2> points = {};
        Color drawColour = BLUE;
    };

    std::vector<Tile> tiles = {};


    void update(float dt);
    void ready(Game* nGame);
    void draw();
    void createTile(Vector2 pos);
    void removeTile(Vector2 pos);
};