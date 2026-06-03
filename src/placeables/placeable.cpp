#include "placeables/placeable.h"
#include <iostream>
#include "game.h"

#include "raylib.h"

using namespace std;

void Placeable::update(float dt) {
}

void Placeable::ready(Game* nGame) {
    game = nGame;
}

void Placeable::draw() {
}