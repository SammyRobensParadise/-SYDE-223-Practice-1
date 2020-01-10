#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
const int MAX_NUMBER_OF_UNIQUE_ARTISTS = 3;

class Music {

private:
    unsigned int dateMade;
    string artistName;
    string musicID;
public:
    Music(int dateMade = 0);

    Music(int dateMade, string artistName, string musicID);

    string get_artist() {
        return artistName;
    }

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
    Song(int songLength = 0);

    Song(int songLength, string genre, string songName);

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
    Playlist()
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
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}