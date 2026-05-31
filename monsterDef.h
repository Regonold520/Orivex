#pragma once

#include <string>
#include <vector>

#include "raylib.h"

class Game;

class MonsterDef {
public:
    Game* game = nullptr;
    struct Monster {
        std::string id;
        std::string trackPath;
        Music music;
        Image sprite;
        Texture2D tex;
    };
    std::vector<Monster> monsters = {};

    void update(float dt);
    void ready(Game* nGame);
    void draw();
    void addMonster(std::string id);
};