// Begüm Özcan - 21302654
// CS201 - 3

#ifndef HOMEWORK1_PLAYER_H
#define HOMEWORK1_PLAYER_H

#include <string>
using namespace std;

class Player {
public:
    Player();
    Player(string name, string position);
    string getName();
    string getPosition();
private:
    string name;
    string position;
};


#endif //HOMEWORK1_PLAYER_H
