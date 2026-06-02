#include "managers/audioManager.h"
#include <iostream>
#include "game.h"

#include "raylib.h"
#include <cmath>

using namespace std;

vector<Music> updatingStreams = {};

bool beatJust = false;
float songTime = 0.0f;

float beatPosition;
float barPosition;

int currentBar;
int beatInBar;

int lastBeat = -1;

Music swamp;

void AudioManager::update(float dt) {
    currentSong.elapsedTime += dt;
    
    songTime += dt;

    beatPosition = songTime / currentSong.secondsPerBeat;
    barPosition = beatPosition / currentSong.timeSig[0];

    currentBar = floor(barPosition);
    

    int currentBeat = (int) floor(beatPosition);

    if (currentBeat != lastBeat){
        lastBeat = currentBeat;

        beatInBar = currentBeat % currentSong.timeSig[0];

        if (beatInBar == 0) {
            PlaySound(strongClick);
        }

        else {
            cout << "Sup" << endl;
            PlaySound(weakClick);

        } 
    }

    for (Music stream : updatingStreams) {
        UpdateMusicStream(stream);
    }
}

void AudioManager::ready(Game* nGame) {
    game = nGame;
    swamp = LoadMusicStream("assets/sounds/swamp.mp3");
    weakClick = LoadSound("assets/sounds/weakClick.mp3");
    strongClick = LoadSound("assets/sounds/strongClick.mp3");

    PlayMusicStream(swamp);
    updatingStreams.push_back(swamp);
    
    changeSong("testSong", "hi", 100.0f);
}

void AudioManager::draw() {
}

void AudioManager::changeSong(string id,string path, float songLength) {
    Song newSong;
    newSong.trackPath = path;
    newSong.songLength = songLength;
    newSong.id = id;

    currentSong = newSong;

    for (CreatureDef::Creature& creature : game->creatureDef.creatures) {
        PlayMusicStream(creature.music);
        updatingStreams.push_back(creature.music);
    }
}