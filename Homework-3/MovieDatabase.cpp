//
// Begum Ozcan - Homework 3
// 21302654
// CS201 - 3
//

#include "MovieDatabase.h"

MovieDatabase::MovieDatabase() {
    moviesHead = NULL;
}

MovieDatabase::~MovieDatabase() {
    if (moviesHead != NULL) {
        MovieNode* temp = moviesHead;

        while(temp != NULL) {
            if(temp->next == NULL) {
                delete temp;
                break;
            }
            else {
                temp = temp->next;
                delete temp->prev;
            }
        }
    }
}

void MovieDatabase::addMovie(const string movieTitle, const string directorFirstName, const string directorLastName,
                             const int releaseDay, const int releaseMonth, const int releaseYear) {

    string movieTitleLower = movieTitle;
    for (int i = 0; i < movieTitle.length(); i++) {
        movieTitleLower[i] = (char) tolower(movieTitle[i]);
    }

    MovieNode *temp = moviesHead;
    while (temp != NULL) {
        if (temp->movie->getMovieTitleLower() == movieTitleLower) {
            cout <<  "Movie already exists" << endl;
            return;
        }
        else {
            temp = temp->next;
        }
    }

    Movie* movie = new Movie(movieTitle, directorFirstName + " " + directorLastName, releaseDay, releaseMonth, releaseYear);
    MovieNode* movieNode = new MovieNode;
    movieNode->movie = movie;
    movieNode->next = NULL;
    movieNode->prev = NULL;

    if (moviesHead == NULL) {
        moviesHead = movieNode;
    }
    else {
        MovieNode* temp = moviesHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = movieNode;
        movieNode->prev = temp;
    }
}


void MovieDatabase::removeMovie(const string movieTitle) {
    if (moviesHead == NULL) {
        cout << "Movie does not exist" << endl;
    }
    else {
        string movieTitleLower = movieTitle;
        for (int i = 0; i < movieTitle.length(); i++) {
            movieTitleLower[i] = (char) tolower(movieTitle[i]);
        }

        MovieNode* temp = moviesHead;
        bool found = false;
        while (temp != NULL && !found) {
            if (temp->movie->getMovieTitleLower() == movieTitleLower) {
                if (temp->prev == NULL) {
                    moviesHead = NULL;
                }
                else {
                    temp->prev->next = temp->next;
                    if (temp->next != NULL)
                        temp->next->prev = temp->prev;
                }
                delete temp;
                found = true;
            }
            else {
                temp = temp->next;
            }
        }
        if (!found) {
            cout << "Movie does not exist" << endl;
        }
    }
}

void MovieDatabase::addActor(const string movieTitle, const string actorFirstName, const string actorLastName,
                             const string actorRole) {
    if (moviesHead == NULL)
        cout << "Movie does not exist" << endl;
    else {
        string movieTitleLower = movieTitle;
        for (int i = 0; i < movieTitle.length(); i++) {
            movieTitleLower[i] = tolower(movieTitle[i]);
        }

        MovieNode* temp = moviesHead;
        bool found = false;
        while (temp != NULL && !found) {
            if (temp->movie->getMovieTitleLower() == movieTitleLower) {
                temp->movie->addActor(actorFirstName, actorLastName, actorRole);
                found = true;
            }
            else {
                temp = temp->next;
            }
        }

        if (!found)
            cout << "Movie does not exist" << endl;
    }
}

void MovieDatabase::removeActor(const string movieTitle, const string actorFirstName, const string actorLastName) {
    if (moviesHead == NULL)
        cout << "Movie does not exist" << endl;
    else {
        string movieTitleLower = movieTitle;
        for (int i = 0; i < movieTitle.length(); i++) {
            movieTitleLower[i] = (char) tolower(movieTitle[i]);
        }

        MovieNode* temp = moviesHead;
        bool found = false;
        while (temp != NULL && !found) {
            if (temp->movie->getMovieTitleLower() == movieTitleLower) {
                temp->movie->removeActor(actorFirstName, actorLastName);
                found = true;
            }
            else {
                temp = temp->next;
            }
        }
    }
}


void MovieDatabase::showAllMovies() {
    if (moviesHead == NULL) {
        cout << "--none--" << endl;
    }
    else {
        MovieNode* temp = moviesHead;
        while (temp != NULL) {
            cout << temp->movie->getMovieTitle() << ", " << temp->movie->getReleaseYear() << ", " << temp->movie->getDirectorName() << endl;
            temp = temp->next;
        }
    }

}


void MovieDatabase::showMovie(const string movieTitle) {
    if (moviesHead == NULL) {
        cout << "Movie does not exist" << endl;
    }
    else {
        string movieTitleLower = movieTitle;
        for (int i = 0; i < movieTitle.length(); i++) {
            movieTitleLower[i] = (char) tolower(movieTitle[i]);
        }

        MovieNode *temp = moviesHead;
        bool found = false;
        while (temp != NULL && !found) {
            if (temp->movie->getMovieTitleLower() == movieTitleLower) {
                cout << temp->movie->getMovieTitle() << endl;
                cout << temp->movie->getReleaseDay() << " / " << temp->movie->getReleaseMonth() << " / " << temp->movie->getReleaseYear() << endl;
                cout << temp->movie->getDirectorName() << endl;
                temp->movie->getActors();
                found = true;
            }
            else {
                temp = temp->next;
            }
        }
        if (!found)
            cout << "Movie does not exist" << endl;
    }
}


void MovieDatabase::showActorRoles(const string actorFirstName, const string actorLastName) {
    if (moviesHead == NULL) {
        cout << "ERROR: No movies in the database!" << endl;
    }
    else {
        cout << actorFirstName + " " + actorLastName << endl;
        string actorFirstNameLower = actorFirstName;
        string actorLastNameLower = actorLastName;
        for (int i = 0; i < actorFirstName.length(); i++) {
            actorFirstNameLower[i] = (char) tolower(actorFirstName[i]);
        }
        for (int j = 0; j < actorLastName.length(); j++) {
            actorLastNameLower[j] = (char) tolower(actorLastName[j]);
        }
        string actorName = actorLastNameLower + actorFirstNameLower;

        MovieNode* temp = moviesHead;
        int printed = 0;
        while (temp != NULL) {
            string role = temp->movie->findActor(actorName);
            if (role != "") {
                cout << role << ", " << temp->movie->getMovieTitle() << ", " << temp->movie->getReleaseYear() << endl;
                printed++;
            }
            temp = temp->next;
        }
        if (printed == 0)
            cout << "--none--" << endl;
    }
}


void MovieDatabase::showMovies(const int releaseYear) {
    if (moviesHead == NULL) {
        cout << "ERROR: No movies in the database!" << endl;
    }
    else {
        cout << releaseYear << endl;
        MovieNode* temp = moviesHead;
        int printed = 0;
        while (temp != NULL) {
            if (temp->movie->getReleaseYear() == releaseYear) {
                cout << temp->movie->getMovieTitle() << ", " << temp->movie->getDirectorName() << ", " << temp->movie->getReleaseDay() << " / "
                    << temp->movie->getReleaseMonth() << endl;
                printed++;
            }
            temp = temp->next;
        }
        if (printed == 0)
            cout << "--none--" << endl;
    }
}
