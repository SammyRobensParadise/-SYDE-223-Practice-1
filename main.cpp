/**
 * @author Sammy Robens-Paradise
 * @author Mary McPhee
 * @date Friday Jan. 10, 2020
 */

#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <random>
#include <chrono>

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
    Music() {
         dateMade = 0;
    };

    /**
     *
     * @param {int} dateMade
     * @param {string} artistName
     * @param {string} musicID
     */
    Music(int init_dateMade, string init_artistName, string init_musicID) {
        dateMade = init_dateMade;
        artistName = init_artistName;
        musicID = init_musicID;
    };

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
    Song() {
        songLength = 0;
    };

    /**
     *
     * @param {int} songLength
     * @param {string} genre
     * @param {string} songName
     */
    Song(int init_songLength, string init_genre, string init_songName) {
        songLength = init_songLength;
        genre = init_genre;
        songName = init_songName;
    };

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
    Playlist(){

    };
    Playlist(vector<Song> init_my_playlist){
        my_playlist = init_my_playlist;
    }


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

    /**
     *
     * @return {vector} my_playlist
     */
    vector<Song> get_songs() {
        return my_playlist;
    }

    /**
     *
     * @return {class} playlistToBeShuffled
     */
    Playlist shuffleSongs() {
        // TODO implement shuffle songs
        Playlist playlistToBeShuffled(my_playlist);
        // get a time-based seed
        unsigned seed = std::chrono::system_clock::now()
                .time_since_epoch()
                .count();
        shuffle(playlistToBeShuffled.get_songs().begin(), playlistToBeShuffled.get_songs().end(),
                std::default_random_engine(seed));
        return playlistToBeShuffled;
    }

    friend vector<Song> operator+(vector<Song> &playlist1, vector<Song> &playlist2);
};

/**
 *
 * @param {vector<Song>} playlist1
 * @param {vector<Song>} playlist2
 * @return {vector<Song>} concatList
 */
vector<Song> operator+(vector<Song> &playlist1, vector<Song> &playlist2) {
    vector<Song> concatList = playlist1;
    concatList.insert(concatList.end(), playlist2.begin(), playlist2.end());
    return concatList;
}


/**a
 * @name main
 * @return {int} 0
 */
int main() {
    Music example(120, "rock", "name");
    const string lame = example.get_artist();
    cout << lame;
    return 0;
}