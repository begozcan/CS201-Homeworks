//
// Begum Ozcan - Homework 3
// 21302654
// CS201 - 3
//

#ifndef HOMEWORK3_ACTOR_H
#define HOMEWORK3_ACTOR_H

#include <string>

using namespace std;

class Actor {
public:
    Actor(string firstName, string lastName, string role);
    Actor();

    string getName();
    string getNameLast();
    string getRole();

private:
    string firstName;
    string lastName;
    string combined;
    string role;
};


#endif //HOMEWORK3_ACTOR_H
