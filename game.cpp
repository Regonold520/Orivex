#include "game.h"
#include "raylib.h"

void Game::ready() {
    InitAudioDevice();
    
    monsterDef.ready(this);
    audioManager.ready(this);
    tileManager.ready(this);
}

void Game::update(float dt) {
    monsterDef.update(dt);
    audioManager.update(dt);
    tileManager.update(dt);
}

void Game::draw() {
    monsterDef.draw();
    audioManager.draw();
    tileManager.draw();
}