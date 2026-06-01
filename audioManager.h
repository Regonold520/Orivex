#pragma once

#include <string>

class Game;

class AudioManager {
public:
    Game* game = nullptr;
    struct Song {
        float elapsedTime = 0.0f;
        std::string trackPath;
        float songLength = 0.0;
        std::string id;
    };
    Song currentSong;

    void update(float dt);
    void ready(Game* nGame);
    void draw();
    void changeSong(std::string id, std::string path, float songLength);
};


