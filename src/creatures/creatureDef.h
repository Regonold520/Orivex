#pragma once

#include <string>
#include <vector>

#include "raylib.h"

class Game;

class CreatureDef {
public:
    Game* game = nullptr;

    struct Creature {
        std::string id;
        std::string trackPath;
        Music music;
        Image sprite;
        Texture2D tex;
    };
    std::vector<Creature> creatures = {};

    void update(float dt);
    void ready(Game* nGame);
    void draw();
    void addCreature(std::string id);
};