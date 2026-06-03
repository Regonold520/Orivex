#pragma once

#include <string>
#include <vector>
#include <filesystem>

#include "raylib.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Game;

class CreatureDef {
public:
    Game* game = nullptr;

    struct CreatureRef {
        Image sprite;
        Texture2D tex;

        std::string id;
        std::string name;
        std::string desc;

        int cost;
        int sellPrice;
        std::string buyCurrency;

        std::vector<std::string> elements;
        std::string rarity;
        int size;

        int genAmount;
        std::string genResource;
    };
    std::vector<CreatureRef> creatureRef = {};

    void update(float dt);
    void ready(Game* nGame);
    void draw();
    void addCreature(std::string id, json creatureData);
    void loadCreature(const std::filesystem::directory_entry& entry);
};