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
    Music();
    Music(int dateMade,string artistName,string musicID);
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}