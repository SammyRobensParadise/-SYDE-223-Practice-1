#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

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
// static_cast<Music>(song_info);
};


class Playlist {
private:
    vector<Song> my_playlist;
public:
    bool Playlist_shuffle_songs(const Song &songToInsert) {
        for (vector<Song>::iterator it = my_playlist.begin(); it != my_playlist.end(); ++it) {
            if (*it == songToInsert) {
                return false;
            };

        };
        return true;
    };

    bool insert_song() {}

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}