// Begüm Özcan - 21302654
// CS201 - 3

#include <iostream>
#include "SocReg.h"
#include "Player.h"
#include "Team.h"
#include <string>

using namespace std;

SocReg::SocReg() {
    teams = NULL;
    noOfTeams = 0;
}

SocReg::~SocReg() {
    for (int i = 0; i < noOfTeams; i++) {
        delete teams[i];
        teams[i]= NULL;
    }
    delete [] teams;
    teams = NULL;
}

void SocReg::addTeam(string teamName, string color) {
    for (int i = 0; teamName[i]; i++) {
        teamName[i] = (char) tolower(teamName[i]);
    }

    for (int c = 0; color[c]; c++) {
        color[c] = (char) tolower(color[c]);
    }

    bool nameExists = false;
    for (int j = 0; j < noOfTeams; j++) {
        if (teams[j]->getName() == teamName)
            nameExists = true;
    }

    if (!nameExists) {
        Team *team = new Team(teamName, color);
        Team** temp = teams;
        teams = new Team*[noOfTeams + 1];
        for(int k = 0; k < noOfTeams; k++) {
            teams[k] = temp[k];
        }
        teams[noOfTeams] = team;
        noOfTeams++;

        delete [] temp;
        temp = NULL;

    }
    else {
        cout << "ERROR: Team alredy exists." << endl;
    }
}


void SocReg::removeTeam(string teamName) {
    int index = -1;

    for (int i = 0; teamName[i]; i++) {
        teamName[i] = (char) tolower(teamName[i]);
    }

    for (int i = 0; i < noOfTeams; i++) {
        if(teams[i]->getName() ==  teamName) {
            index = i;
        }
    }

    if(index != -1) {
        Team** temp = teams;
        delete temp[index];
        temp[index] == NULL;

        noOfTeams--;

        teams = new Team*[noOfTeams];
        for (int j = 0; j < index; j++) {
            teams[j] = temp[j];
        }
        for(int k = index; k < noOfTeams; k++) {
            teams[k] = temp[k+1];
        }

        delete [] temp;
        temp = NULL;
    }
    else {
        cout << "ERROR: Team does not exist. Cannot be removed." << endl;
    }

}

void SocReg::addPlayer(string teamName, string playerName, string playerPosition) {
    for (int i = 0; teamName[i]; i++) {
        teamName[i] = (char) tolower(teamName[i]);
    }

    int index = -1;
    for(int j = 0; j < noOfTeams; j++) {
        if(teams[j]->getName() == teamName) {
            index = j;
        }
    }

    if (index != -1) {
        for(int k = 0; playerName[k]; k++) {
            playerName[k] = (char) tolower(playerName[k]);
        }

        for(int a = 0; playerPosition[a]; a++) {
            playerPosition[a] = (char) tolower(playerPosition[a]);
        }

        bool success = teams[index]->addPlayer(playerName, playerPosition);

        if(!success) {
            cout << "ERROR: Player already exists." << endl;
        }
    }
    else {
        cout << "ERROR: Team does not exist." << endl;
    }
}


void SocReg::removePlayer(string teamName, string playerName) {
    for (int i = 0; teamName[i]; i++) {
        teamName[i] = (char) tolower(teamName[i]);
    }

    int index = -1;
    for(int j = 0; j < noOfTeams; j++) {
        if(teamName == teams[j]->getName()) {
            index = j;
        }
    }

    if(index != -1) {
        for (int k = 0; playerName[k]; k++) {
            playerName[k] = (char) tolower(playerName[k]);
        }

        bool success = teams[index]->removePlayer(playerName);

        if(!success) {
            cout << "ERROR: Player does not exist." << endl;
        }
    }
    else{
        cout << "ERROR: Team does not exist." << endl;
    }
}

void SocReg::displayAllTeams() {
    if(noOfTeams == 0) {
        cout << "--EMPTY--" << endl;
    }
    else {
        for(int i = 0; i < noOfTeams; i++) {
            cout << teams[i]->getName() << ", " << teams[i]->getColor() << endl;
        }
    }
}


void SocReg::displayPlayer(string playerName) {
    for (int k = 0; playerName[k]; k++) {
        playerName[k] = (char) tolower(playerName[k]);
    }

    cout << playerName << endl;
    int occurrences = 0;
    for(int i = 0; i < noOfTeams; i++) {
        string position = teams[i]->getPlayerPosition(playerName);
        if(position != "") {
            cout << position << ", " << teams[i]->getName() << ", " << teams[i]->getColor() << endl;
            occurrences++;
        }
    }

    if(occurrences == 0) {
        cout << "--EMPTY--" << endl;
    }

}


void SocReg::displayTeam(string teamName) {
    for (int i = 0; teamName[i]; i++) {
        teamName[i] = (char) tolower(teamName[i]);
    }
    bool exists = false;
    for (int k = 0; k < noOfTeams; k++) {
        if(teams[k]->getName() == teamName) {
            exists = true;
        }
    }
    if(exists) {
        for (int j = 0; j < noOfTeams; j++) {
            if (teamName == teams[j]->getName()) {
                cout << teams[j]->getName() << ", " << teams[j]->getColor() << endl;
                teams[j]->displayPlayers();
            }
        }
    }
    else {
        cout << "ERROR: Team does not exist." << endl;
    }

}
