#include <iostream>
#include <vector>
#include <string>

#include "raylib.h"

#include "game.h"
Game game;

using namespace std;

const int screenWidth = 800;
const int screenHeight = 450;

float deltaTimer = 0.0f;

void ready() {
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    game.ready();
    SetTargetFPS(60); 
}

void update(float dt) {
    game.update(dt);
    
    deltaTimer += dt;
}

void draw() {
    BeginDrawing();


    ClearBackground(RAYWHITE);
    game.draw();
    string txt = "Current Song = "+ game.audioManager.currentSong.id  +", Time = " + to_string(game.audioManager.currentSong.elapsedTime) + " s";

    DrawText(txt.c_str(), 10, 10, 20, LIGHTGRAY);


    EndDrawing();
}

int main() {
    
    ready();

    while (!WindowShouldClose())
    {
        update(GetFrameTime());
        
        draw();
    }

    CloseWindow();

    return 0;
}