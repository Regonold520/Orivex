#include "raylib.h"

class Game;

class Placeable {
public:
    Game* game = nullptr;

    void update(float dt);
    void ready(Game* nGame);
    void draw();
};