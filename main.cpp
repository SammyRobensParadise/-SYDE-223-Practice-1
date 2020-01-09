#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Music{

private:
   unsigned int dateMade;
   string artistName;
   string musicID;
public:
    Music(int dateMade = 0);
    Music(int dateMade,string artistName,string musicID);
    string get_artist(){
        return artistName;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}