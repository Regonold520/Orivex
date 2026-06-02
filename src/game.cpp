#include <iostream>
#include "game.h"

#include "rlgl.h"
#include "raymath.h"
#include "raylib.h"

using namespace std;

void Game::ready() {
    InitAudioDevice();

    camera.target = {0,0};
    camera.offset = {0,0};
    camera.rotation = 0.0f;
    camera.zoom = 0.3f;

    creatureDef.ready(this);
    audioManager.ready(this);
    tileManager.ready(this);
    mouseManager.ready(this);
}

float speed = 3.0f;




void Game::update(float dt) {
    Vector2 dir = {0,0};
    if (IsKeyDown(KEY_A)) dir.x -= speed;
    if (IsKeyDown(KEY_D)) dir.x += speed;
    if (IsKeyDown(KEY_S)) dir.y += speed;
    if (IsKeyDown(KEY_W)) dir.y -= speed;

    camera.target = {camera.target.x + dir.x,camera.target.y + dir.y};

    creatureDef.update(dt);
    audioManager.update(dt);
    tileManager.update(dt);
    mouseManager.update(dt);
}

void Game::draw() {
    BeginMode2D(camera);

    creatureDef.draw();
    audioManager.draw();
    tileManager.draw();
    mouseManager.draw();

    EndMode2D();
}