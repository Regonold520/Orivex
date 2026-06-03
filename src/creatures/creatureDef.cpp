#include "creatures/creatureDef.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "game.h"

#include "raylib.h"
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

namespace fileS = std::filesystem;

void CreatureDef::update(float dt) {
}

void CreatureDef::loadCreature(const fileS::directory_entry& entry) {
    string basePath = entry.path().string() + "/";
    string creatureId = entry.path().filename().string();

    ifstream file(basePath + creatureId + ".json");
    json data;
    file >> data;

    addCreature(creatureId, data);
}

void CreatureDef::ready(Game* nGame) {
    game = nGame;

    for (const auto& entry : fileS::directory_iterator("assets/creatures")) {
        if (entry.is_directory()) {
            loadCreature(entry);
        }
    }
}


void CreatureDef::draw() {
    for (CreatureRef& creature : creatureRef) {
        DrawTexture(creature.tex, 800/2 - creature.tex.width/2, 450/2 - creature.tex.height/2 - 40, WHITE);
    }
}

void CreatureDef::addCreature(string id, json creatureData) {
    bool has = false;
    for (CreatureRef m : creatureRef) {
        if (m.id == id) {
            has = true;
        }
    }

    if (!has){
        CreatureRef newRef;
        newRef.id = id;
        string imgPath = "assets/sprites/"+id+".png";
        newRef.sprite = LoadImage(imgPath.c_str());
        newRef.tex = LoadTextureFromImage(newRef.sprite);

        newRef.name = creatureData["name"];
        newRef.desc = creatureData["desc"];

        newRef.cost = creatureData["cost"];
        newRef.sellPrice = creatureData["sellPrice"];
        newRef.buyCurrency = creatureData["currency"];

        for (string elem : creatureData["elements"]) {
            newRef.elements.push_back(elem);
        }

        newRef.rarity = creatureData["rarity"];
        newRef.size = creatureData["size"];

        newRef.genAmount = creatureData["generation"]["amount"];
        newRef.genResource = creatureData["generation"]["resource"];

        SetTextureFilter(newRef.tex, TEXTURE_FILTER_BILINEAR);

        creatureRef.push_back(newRef);
    }
}