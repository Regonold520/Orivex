#include "managers/mouseManager.h"
#include <iostream>
#include "game.h"

#include "rlgl.h"
#include "raymath.h"
#include "raylib.h"

using namespace std;


float Sign(Vector2 p1, Vector2 p2, Vector2 p3) {
    return (p1.x - p3.x) * (p2.y - p3.y)
         - (p2.x - p3.x) * (p1.y - p3.y);
}

bool CheckTrianglePoint(Vector2 mouse, Vector2 p1, Vector2 p2, Vector2 p3) {
    float d1 = Sign(mouse, p1, p2);
    float d2 = Sign(mouse, p2, p3);
    float d3 = Sign(mouse, p3, p1);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}

void MouseManager::update(float dt) {
    Vector2 mouseScreen = GetMousePosition();
    Vector2 mouseWorld = GetScreenToWorld2D(mouseScreen, game->camera);

    
    Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), game->camera);
    float wheel = GetMouseWheelMove();
    if (wheel != 0)
    {
        

        game->camera.offset = GetMousePosition();

        game->camera.target = mouseWorldPos;

        float scale = 0.2f*wheel;
        game->camera.zoom = Clamp(expf(logf(game->camera.zoom)+scale), 0.125f, 64.0f);
    }

    for (TileManager::Tile& tile : game->tileManager.tiles) {
        if (tile.points.size() == 4){
            if (CheckTrianglePoint(mouseWorldPos, tile.points[0], tile.points[3], tile.points[1]) ||
                CheckTrianglePoint(mouseWorldPos, tile.points[2], tile.points[1], tile.points[3])){
                tile.drawColour = RED;
            } else {
                tile.drawColour = BLUE;
            }
        }
    }
}

void MouseManager::ready(Game* nGame) {
    game = nGame;
}


void MouseManager::draw() {
}