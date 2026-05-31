#pragma once

class Game;

class TileManager {
public:
    Game* game = nullptr;

    void update(float dt);
    void ready(Game* nGame);
    void draw();
};