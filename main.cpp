/**
 * @author Sammy Robens-Paradise
 * @author Mary McPhee
 * @date Friday Janurary 10, 2020
 */

#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

/** @namespace {std} */
using namespace std;

// constants
const int MAX_NUMBER_OF_UNIQUE_ARTISTS = 3;

class Music {

private:
    unsigned int dateMade;
    string artistName;
    string musicID;
public:
    /**
     *
     * @param {int} dateMade
     */
    Music(int dateMade = 0);
    /**
     *
     * @param {int} dateMade
     * @param {string} artistName
     * @param {string} musicID
     */
    Music(int dateMade, string artistName, string musicID);
    /**
     *
     * @return {string} artistName
     */
    string get_artist() {
        return artistName;
    }
    /**
     *
     * @param {Music} comp2
     * @return boolean
     */
    bool operator==(const Music &comp2) {
        return dateMade == comp2.dateMade &&
               artistName == comp2.artistName
               && musicID == comp2.musicID;
    }
};

class Song : public Music {
private:
    unsigned int songLength;
    string genre;
    string songName;

public:
    /**
     *
     * @param {int} songLength
     */
    Song(int songLength = 0);
    /**
     *
     * @param {int} songLength
     * @param {string} genre
     * @param {string} songName
     */
    Song(int songLength, string genre, string songName);
    /**
     *
     * @param {Song} comp2
     * @return
     */
    bool operator==(const Song &comp2) {
        return songLength == comp2.songLength &&
               genre == comp2.genre &&
               songName == comp2.songName;
    }
};


class Playlist {
private:
    vector<Song> my_playlist;
public:
    /**
     * constructor
     */
    Playlist();
    /**
     * insert_songs
     * @param {Song} songToInsert
     * @return bool
     */
    bool insert_songs(const Song &songToInsert) {
        string artistName = static_cast<Music>(songToInsert).get_artist();
        int unique_artist_count = 0;
        for (vector<Song>::iterator it = my_playlist.begin(); it != my_playlist.end(); ++it) {
            if (artistName == static_cast<Music>(*it).get_artist()) {
                unique_artist_count++;
            }
            if (*it == songToInsert || unique_artist_count > MAX_NUMBER_OF_UNIQUE_ARTISTS) {
                return false;
            }
        }
        my_playlist.push_back(songToInsert);
        return true;
    };

    Playlist shuffleSongs(){
        // TODO implement shuffle songs

    }
};

/**a
 * @name main
 * @return {int} 0
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}