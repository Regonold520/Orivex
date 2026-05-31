#include "monsterDef.h"
#include <iostream>
#include "game.h"

#include "raylib.h"

using namespace std;

void MonsterDef::update(float dt) {
    
}

void MonsterDef::ready(Game* nGame) {
    game = nGame;
    addMonster("plucklint");
    addMonster("repatillo");
}


void MonsterDef::draw() {
    for (Monster& mon : monsters) {
        DrawTexture(mon.tex, 800/2 - mon.tex.width/2, 450/2 - mon.tex.height/2 - 40, WHITE);
    }
}

void MonsterDef::addMonster(string id) {
    bool has = false;
    for (Monster m : monsters) {
        if (m.id == id) {
            has = true;
        }
    }

    if (!has){
        Monster newMon;
        newMon.id = id;
        newMon.trackPath = "assets/sounds/"+id+"/"+id+"1.mp3";
        newMon.music = LoadMusicStream(newMon.trackPath.c_str());
        string imgPath = "assets/sprites/"+id+".png";
        newMon.sprite = LoadImage(imgPath.c_str());
        newMon.tex = LoadTextureFromImage(newMon.sprite);

        monsters.push_back(newMon);
    }
}