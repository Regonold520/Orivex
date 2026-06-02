#include "creatures/creatureDef.h"
#include <iostream>
#include "game.h"

#include "raylib.h"

using namespace std;

void CreatureDef::update(float dt) {
}

void CreatureDef::ready(Game* nGame) {
    game = nGame;
}


void CreatureDef::draw() {
    for (Creature& creature : creatures) {
        DrawTexture(creature.tex, 800/2 - creature.tex.width/2, 450/2 - creature.tex.height/2 - 40, WHITE);
    }
}

void CreatureDef::addCreature(string id) {
    bool has = false;
    for (Creature m : creatures) {
        if (m.id == id) {
            has = true;
        }
    }

    if (!has){
        Creature newCreature;
        newCreature.id = id;
        newCreature.trackPath = "assets/sounds/"+id+"/"+id+"1.mp3";
        newCreature.music = LoadMusicStream(newCreature.trackPath.c_str());
        string imgPath = "assets/sprites/"+id+".png";
        newCreature.sprite = LoadImage(imgPath.c_str());
        newCreature.tex = LoadTextureFromImage(newCreature.sprite);

        creatures.push_back(newCreature);
    }
}