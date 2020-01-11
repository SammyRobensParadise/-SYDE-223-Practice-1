/**
 * @author Sammy Robens-Paradise
 * @author Mary McPhee
 * @date Friday Jan. 10, 2020
 */

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <math.h>
#include <random>

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

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
        // TODO
        // remove after testing
        artistName = "test name";
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

class MusicTest {
    Music musicTester1;
    Music musicTester2;
    Music musicTester3;
public:
    // initialize object values
    void setup() {
        musicTester1 = Music(8, "Queen", "Under Pressure");
        musicTester2 = Music(8, "Queen", "Under Pressure");
        musicTester3 = Music(6, "Nina Simone", "Feeling Good");
    }

    /**
     *
     * @return
     */
    bool testGetArtist() {
        musicTester1.get_artist();
        ASSERT_TRUE(musicTester1.get_artist() == "Queen");
        ASSERT_FALSE(musicTester1.get_artist() != "Queen");
        return true;
    }

    bool testMusicComp() {
        cout << "running... \n";
        ASSERT_TRUE(musicTester1 == musicTester2);
        cout << "Passed: Comparison of equal objects\n";
        ASSERT_FALSE(musicTester2 == musicTester3);
        cout << "Passed: Comparison of unequal objects\n";
        return true;
    }

    void tearDown() {
    }

    /*
     * test runner for MusicTest class
     */
    void runTest() {
        cout << "Testing Music class...\n";
        setup();
        cout << "testing MusicComp()\n";
        cout << (testMusicComp() ? "PASS: all assertions passed successfully \n" : "FAIL: some assertions failed \n");
        cout << "testing getArtist()  \n";
        cout << (testGetArtist() ? "PASS: all assertions passed successfully \n" : "FAIL: some assertions failed \n");
        tearDown();
        cout << "Done!\n";
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
     * /param constructor for playlist class
     * explicitly calls param constructor for base
     * music class
     * @param {int} songLength
     * @param {string} genre
     * @param {string} songName
     * @param {int} dateMade `Music`
     * @param {string} artistName `Music`
     * @param {string} musicID `music`
     */
    Song(int init_songLength, string init_genre, string init_songName, int init_dateMade, string init_artistName,
         string init_musicID) : Music(init_dateMade, init_artistName, init_musicID) {
        songLength = init_songLength;
        genre = init_genre;
        songName = init_songName;
    };

    /**
     *
     * @return {string} songName
     */
    string get_name() {
        return songName;
    }

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

// Song test class

class SongTest : public Music {
    Song songInstanceComp1;
    Song songInstanceComp2;
    Song songInstanceComp3;
public:
    /**
     * void setup called
     */
    void setup() {
        songInstanceComp1 = Song(124, "rap", "fight this feeling", 2015, "M. Miller", "124");
        songInstanceComp2 = Song(124, "rap", "fight this feeling", 2015, "M. Miller", "124");
        songInstanceComp3 = Song(124, "rock and roll", "brown sugar", 1967, "Rolling Stones", "142");

    }

    /**
     *
     * @return true
     */
    bool testSongComp() {
        cout << "running... \n";
        ASSERT_TRUE(songInstanceComp1 == songInstanceComp2)
        cout << "Passed: comparison of equal objects \n";
        ASSERT_FALSE(songInstanceComp2 == songInstanceComp3)
        cout << "Passed: comparison of unequal objects \n";
        return true;
    }

    void tearDown() {
    }

    /**
     * test runner for SongTest class
     * @test Song
     */
    void runTest() {
        cout << "Testing Song Class... \n";
        setup();

        cout << (testSongComp() ? "PASS: all assertions passed successfully \n" : "FAIL: some assertions failed \n");
        tearDown();
        cout << "Done! \n" << endl;
    }

};

class Playlist {
private:
    vector<Song> my_playlist;
public:
    /**
     * constructor
     */
    Playlist() {

    };

    /**
     *
     * @param init_my_playlist
     */
    Playlist(vector<Song> initPlaylist) {
        my_playlist = initPlaylist;
    }


    /**
     * insert_songs
     * @param {Song} songToInsert
     * @return bool
     */
    bool insertSongs(Song &songToInsert) {
        string artistName = static_cast<Music>(songToInsert).get_artist();
        cout << "Artist Name: " << artistName << "\n";
        int unique_artist_count = 0;
        for (vector<Song>::iterator it = my_playlist.begin(); it != my_playlist.end(); ++it) {
            if (artistName == static_cast<Music>(*it).get_artist()) {
                unique_artist_count++;
            }
            if (*it == songToInsert || unique_artist_count > MAX_NUMBER_OF_UNIQUE_ARTISTS) {
                cout << "ERR: unable to add songs \n";
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
    void shuffleSongs() {
        srand(time(0));
        for (int i = 0; i < my_playlist.size(); i++) {
            int index1 = rand() % my_playlist.size();
            int index2 = rand() % my_playlist.size();
            swap(my_playlist[index1], my_playlist[index2]);
        }
    }

    friend vector<Song> operator+(vector<Song> &playlist1, vector<Song> &playlist2);
};

class PlaylistTest {
    Song testSong1;
    Song testSong2;
    Song testSong3;
    Song testSong4;
    Song testSong5;
    Playlist playlistInstance1;
    Playlist playlistInstance2;

public:
    void setup() {
        testSong1 = Song(124, "rap", "fight this feeling", 2015, "M. Miller", "124");
        testSong2 = Song(124, "rap", "fight this feeling", 2015, "M. Miller", "124");
        testSong3 = Song(145, "R&B", "Nights", 2016, "Frank Ocean", "354");
        testSong4 = Song(132, "Blues", "Blues No. 9", 1933, "Buddy Guy", "775");
        testSong5 = Song(121, "Regge", "One Love", 1972, "Bob Marley", "674");
        vector<Song> playlistTest = {testSong1, testSong2, testSong3, testSong4};
        playlistInstance1 = Playlist(playlistTest);
    };

    bool testInsertSongs() {
        cout << "testing insertSongs() \n";
        cout << "Inserting normal Song... \n";
        playlistInstance1.insertSongs(testSong5);
        cout << "Getting updated size... \n";
        int playlistSize = playlistInstance1.get_songs().size()-1;
        ASSERT_TRUE(playlistInstance1.get_songs().at(playlistSize) == testSong5)
        cout << "PASS: additional song added \n";
        cout << "Inserting duplicate songs... \n";
        ASSERT_TRUE(playlistInstance1.insertSongs(testSong1) == false)
        cout << "PASS: songs were not added \n";
        return true;
    }

    bool testShuffleSongs() {
        cout << "testing shuffleSongs() \n";
        cout << "creating vector... \n";
        vector<Song> initInstance = playlistInstance1.get_songs();
        cout << "shuffling songs... \n";
        playlistInstance1.shuffleSongs();
        bool passedTest = false;
        for (int s = 0; s < initInstance.size(); s++) {
            if (!(initInstance[s] == playlistInstance1.get_songs()[s])) {
                passedTest = true;
                break;
            }
        }
        ASSERT_TRUE(passedTest);
        cout << "PASS: shuffling \n";
        return true;
    }

    void tearDown() {

    }

    void runTest() {
        cout << "Testing Playlist Class... \n";
        setup();
        cout << (testShuffleSongs() ? "PASS: all assertions passed successfully \n"
                                    : "FAIL: some assertions failed \n");
        cout << (testInsertSongs() ? "PASS: all assertions passed successfully \n"
                                   : "FAIL: some assertions failed \n");
        tearDown();
        cout << "Done! \n" << endl;
    }
};

/**
 * overload
 * @param {vector<Song>} playlist1
 * @param {vector<Song>} playlist2
 * @return {vector<Song>} concatList
 */
vector<Song> operator+(vector<Song> &playlist1, vector<Song> &playlist2) {
    vector<Song> concatList = playlist1;
    concatList.insert(concatList.end(), playlist2.begin(), playlist2.end());
    return concatList;
}


/**
 * @name main
 * @return {int} 0
 */
int main() {
    cout << endl;
    cout << "- - - - - - - -" << endl;
    SongTest songTestRunner;
    songTestRunner.runTest();
    cout << endl;
    cout << "- - - - - - - -" << endl;
    MusicTest musicTestRunner;
    musicTestRunner.runTest();
    cout << endl;
    cout << "- - - - - - - -" << endl;
    PlaylistTest playlistTestRunner;
    playlistTestRunner.runTest();
    cout << endl;
    cout << "- - - - - - - -" << endl;
    return 0;
}