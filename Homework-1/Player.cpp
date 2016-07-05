// Begüm Özcan - 21302654
// CS201 - 3

#include "Player.h"

Player::Player() {
    name = "default";
    position = "default";
}

Player::Player(string name, string position) {
    this->name = name;
    this->position = position;
}

string Player::getName(){
    return name;
}

string Player::getPosition(){
    return position;
}