#pragma once

#include <string>

#include "raylib.h"

class Game;

class AudioManager {
public:
    Game* game = nullptr;
    struct Song {
        float elapsedTime = 0.0f;
        std::string trackPath;
        float songLength = 0.0;
        std::string id;

        float bpm = 120.0f;
        int timeSig[2] = {3,4};
        float secondsPerBar = (timeSig[0] * (60/bpm));
        float secondsPerBeat = (60/bpm) * (4.0f / timeSig[1]);
    };
    Song currentSong;
    Sound weakClick;
    Sound strongClick;

    void update(float dt);
    void ready(Game* nGame);
    void draw();
    void changeSong(std::string id, std::string path, float songLength);
};


