#include "creatures/creature.h"
#include <iostream>
#include "game.h"

#include "raylib.h"

using namespace std;

void Creature::update(float dt) {
}

void Creature::ready(Game* nGame) {
    game = nGame;
}

void Creature::draw() {
}