//
// Begum Ozcan - Homework 3
// 21302654
// CS201 - 3
//

#ifndef HOMEWORK3_MOVIE_H
#define HOMEWORK3_MOVIE_H

#include <string>
#include <iostream>
#include "Actor.h"

using namespace std;

class Movie {
public:
    Movie(string movieTitle, string directorName, int releaseDay, int releaseMonth, int releaseYear);
    Movie();
    ~Movie();

    string getDirectorName();
    string getMovieTitle();
    string getMovieTitleLower();
    int getReleaseDay();
    int getReleaseMonth();
    int getReleaseYear();
    void getActors();
    string findActor(string actorName);

    void addActor(const string actorFirstName, const string actorLastName, const string actorRole);
    void removeActor(const string actorFirstName, const string actorLastName);

private:
    struct ActorNode {
        Actor actor;
        ActorNode* next;
    };

    string movieTitle;
    string movieTitleLower;
    string directorName;
    int releaseDay;
    int releaseMonth;
    int releaseYear;

    ActorNode* actorHead;

};


#endif //HOMEWORK3_MOVIE_H
