#pragma once

class Game;

class CreatureManager {
public:
    Game* game = nullptr;

    std::vector<Creature> creatures = {};

    void update(float dt);
    void ready(Game* nGame);
    void draw();
    void addCreature(std::string id);
};