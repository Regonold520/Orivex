#include "audioManager.h"
#include <iostream>
#include "game.h"

#include "raylib.h"

using namespace std;

vector<Music> updatingStreams = {};

void AudioManager::update(float dt) {
    currentSong.elapsedTime += dt;
    

    for (Music stream : updatingStreams) {
        UpdateMusicStream(stream);
    }
}

void AudioManager::ready(Game* nGame) {
    game = nGame;
    
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

    for (MonsterDef::Monster& mon : game->monsterDef.monsters) {
        PlayMusicStream(mon.music);
        updatingStreams.push_back(mon.music);
    }
}