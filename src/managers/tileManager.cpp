#include "managers/tileManager.h"
#include <iostream>
#include "game.h"

#include "raylib.h"

using namespace std;



void TileManager::ready(Game* nGame) {
    game = nGame;

    int size = 10;

    for (int x=0 ; x<size ; x++) {
        for (int y=0 ; y<size ; y++) {
            createTile({x,y});
        }
    }
}

void TileManager::update(float dt) {
    if (selectedTiles.size() > 0) {
        for (TileManager::Tile& tile : game->tileManager.tiles) {
            bool match = false;
            for (TileManager::Tile& checkT : game->tileManager.selectedTiles) {

                if (tile.pos.x == checkT.pos.x && tile.pos.y == checkT.pos.y) {
                    match = true;
                }
            }

            if (match) {
                tile.drawColour = RED;
            } else {
                tile.drawColour = BLUE;
            }
        }
    }
}   

void drawTile(float x, float y, float width, float height, TileManager::Tile& tile) {
    Vector2 top = {x, y - height / 2};
    Vector2 right = {x + width / 2, y};
    Vector2 bottom = {x, y + height / 2};
    Vector2 left = {x - width / 2, y};
    
    if (tile.points.size() <= 0) {
        tile.points = {
            top, right, bottom, left
        };
    }
    
    DrawTriangle(bottom, right, left, tile.drawColour);
    DrawTriangle(top, left, right, tile.drawColour);
}

void TileManager::computeSelection(Vector2 topTile, int scale) {
    selectedTiles.clear();
    for (int x=0;x<scale;x++) {
        for (int y=0;y<scale;y++) {
            Vector2 targetPos = {getTile(topTile).pos.x + x, getTile(topTile).pos.y + y};
            
            selectedTiles.push_back(getTile(targetPos));
        }
    }
}

int mult = 30;
float tileSpacing = 1.1f;
Vector2 tileStart = {400,100};

bool debugText = false;

void TileManager::draw() {
    
    for (Tile& tile : tiles) {
        Vector2 tileDrawPos = {((tile.pos.x - tile.pos.y)* mult*1) + tileStart.x,
                                ((tile.pos.y + tile.pos.x) * mult/2) + tileStart.y};
        drawTile(tileDrawPos.x*tileSpacing,tileDrawPos.y*tileSpacing , 2 * mult, 1 * mult, tile);
        
        if (debugText) {
            string txt = to_string((int)tile.pos.x) + "," + to_string((int)tile.pos.y);

            DrawText(txt.c_str(), tileDrawPos.x *tileSpacing, tileDrawPos.y*tileSpacing, 20, BLACK);
        }
    }
}

void TileManager::createTile(Vector2 pos) {
    Tile newTile;
    newTile.pos = pos;

    tiles.push_back(newTile);
}

void TileManager::removeTile(Vector2 pos) {
    int c = 0;
    for (Tile& tile : tiles) {
        if (tile.pos.x == pos.x && tile.pos.y == pos.y) {
            tiles.erase(tiles.begin() + c);
        }
        c++;
    }
}

TileManager::Tile TileManager::getTile(Vector2 pos) {
    for (Tile& tile : tiles) {
        if (tile.pos.x == pos.x && tile.pos.y == pos.y) {
            return tile;
        }
    }
    return Tile{{-999,1}};
}