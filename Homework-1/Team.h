// Begüm Özcan - 21302654
// CS201 - 3

#ifndef HOMEWORK1_TEAM_H
#define HOMEWORK1_TEAM_H

#include <string>
#include "Player.h"

using namespace std;

class Team {
public:
    Team();
    Team(string name, string color);
    ~Team();
    string getName();
    string getColor();
    bool addPlayer(string playerName, string playerPosition);
    bool removePlayer(string playerName);
    string getPlayerPosition(string playerName);
    void displayPlayers();

private:
    string name;
    string color;
    Player** players;
    int noOfPlayers;
};

#endif //HOMEWORK1_TEAM_H
