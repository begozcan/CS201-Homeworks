// Begüm Özcan - 21302654
// CS201 - 3

#ifndef HOMEWORK1_SOCREG_H
#define HOMEWORK1_SOCREG_H

#include <string>
#include "Player.h"
#include "Team.h"

class SocReg {
public:
    SocReg();
    ~SocReg();
    void addTeam( string teamName, string color );
    void removeTeam( string teamName );
    void addPlayer( string teamName, string playerName, string playerPosition );
    void removePlayer( string teamName, string playerName );
    void displayAllTeams();
    void displayPlayer( string playerName );
    void displayTeam( string teamName );

private:
    Team** teams;
    int noOfTeams;
};

#endif //HOMEWORK1_SOCREG_H
