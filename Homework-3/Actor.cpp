//
// Begum Ozcan - Homework 3
// 21302654
// CS201 - 3
//

#include "Actor.h"

Actor::Actor(string firstName, string lastName, string role) {
    this->firstName = firstName;
    this->lastName = lastName;
    for (int i = 0; i < firstName.length(); i++) {
        firstName[i] = tolower(firstName[i]);
    }
    for (int i = 0; i < lastName.length(); i++) {
        lastName[i] = tolower(lastName[i]);
    }
    this->combined = lastName + firstName;
    this->role = role;
}

Actor::Actor() {
    this->firstName = "";
    this->lastName = "";
    this->role = "";
}

string Actor::getName() {
    return firstName + " " + lastName;
}

string Actor::getNameLast() {
    return combined;
}


string Actor::getRole() {
    return role;
}
