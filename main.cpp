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

    friend bool operator==(const Music &comp1, const Music &comp2);
};

bool operator==(const Music &comp1, const Music &comp2) {
    return comp1.dateMade == comp2.dateMade &&
           comp1.artistName == comp2.artistName
           && comp1.musicID == comp2.musicID;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}