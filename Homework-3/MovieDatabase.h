//
// Begum Ozcan - Homework 3
// 21302654
// CS201 - 3
//

#ifndef HOMEWORK3_MOVIEDATABASE_H
#define HOMEWORK3_MOVIEDATABASE_H

#include <string>
#include "Movie.h"

using namespace std;

class MovieDatabase {

public:

    MovieDatabase();
    ~ MovieDatabase();

    void addMovie(const string movieTitle, const string directorFirstName, const string directorLastName, const int releaseDay,
                  const int releaseMonth, const int releaseYear);
    void removeMovie(const string movieTitle);
    void addActor(const string movieTitle, const string actorFirstName, const string actorLastName, const string actorRole);
    void removeActor(const string movieTitle, const string actorFirstName, const string actorLastName);
    void showAllMovies();
    void showMovie(const string movieTitle);
    void showActorRoles(const string actorFirstName, const string actorLastName);
    void showMovies(const int releaseYear);

private:
    struct MovieNode {
        Movie* movie;
        MovieNode* next;
        MovieNode* prev;
        ~MovieNode() {
            if (movie != NULL)
                delete movie;
        }
    };

    MovieNode* moviesHead;
};

#endif //HOMEWORK3_MOVIEDATABASE_H
