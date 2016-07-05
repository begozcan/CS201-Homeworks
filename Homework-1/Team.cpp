// Begüm Özcan - 21302654
// CS201 - 3

#include "Team.h"
#include "Player.h"
#include <string>
#include <iostream>

Team::Team() {
    name = "default";
    color = "default";
    players = NULL;
    noOfPlayers = 0;
}

Team::Team(string name, string color) {
    this->name = name;
    this->color = color;
    players = NULL;
    noOfPlayers = 0;
}

Team::~Team() {
    for (int i = 0; i < noOfPlayers; i++) {
        delete players[i];
        players[i] = NULL;
    }
    delete [] players;
    players = NULL;
}

string Team::getName() {
    return name;
}

string Team::getColor() {
    return color;
}

bool Team::addPlayer(string playerName, string playerPosition) {
    for(int k = 0; k < noOfPlayers; k++) {
        if(playerName == players[k]->getName()) {
            return false;
        }
    }

    Player** temp = players;
    players = new Player*[noOfPlayers + 1];
    for (int i = 0; i < noOfPlayers; i++) {
        players[i] = temp[i];
    }

    players[noOfPlayers] = new Player(playerName, playerPosition);
    noOfPlayers++;

    delete [] temp;
    temp = NULL;

    return true;
}

bool Team::removePlayer(string playerName) {
    bool isFound = false;
    for (int i = 0; i < noOfPlayers; i++) {
        if(playerName == players[i]->getName()) {
            isFound = true;
            Player** temp = players;
            delete temp[i];
            temp[i] = NULL;

            noOfPlayers--;
            players = new Player*[noOfPlayers];

            for(int j = 0; j < i; j++) {
                players[j] = temp[j];
            }

            for (int k = i; k < noOfPlayers; k++) {
                players[k] = temp[k + 1];
            }

            delete [] temp;
            temp = NULL;
        }
    }
    return isFound;
}

string Team::getPlayerPosition(string playerName) {
    for (int i = 0; i < noOfPlayers; i++) {
        if(playerName == players[i]->getName()) {
            return players[i]->getPosition();
        }
    }

    return "";
}

void Team::displayPlayers() {
    if(noOfPlayers == 0) {
        cout << "--EMPTY--" << endl;
    }
    else {
        for (int i = 0; i < noOfPlayers; i++) {
            cout << players[i]->getName() << ", " << players[i]->getPosition() << endl;
        }
    }
}
