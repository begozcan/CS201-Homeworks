//
// Begum Ozcan - Homework 3
// 21302654
// CS201 - 3
//

#include "Movie.h"

using namespace std;

Movie::Movie(string movieTitle, string directorName, int releaseDay, int releaseMonth, int releaseYear) {
    this->movieTitle = movieTitle;
    for (int i = 0; i < movieTitle.length(); i++) {
        movieTitle[i] = (char) tolower(movieTitle[i]);
    }
    this->movieTitleLower = movieTitle;
    this->directorName = directorName;
    this->releaseDay = releaseDay;
    this->releaseMonth = releaseMonth;
    this->releaseYear = releaseYear;
    this->actorHead = NULL;
}

Movie::Movie() {
    this->movieTitle = "";
    this->directorName = "";
    this->releaseDay = 0;
    this->releaseMonth = 0;
    this->releaseYear = 0;
    this->actorHead = NULL;
}

Movie::~Movie() {
    if (actorHead != NULL) {
        ActorNode* prev = actorHead;
        ActorNode* cur = actorHead->next;

        while (cur != NULL) {
            delete prev;
            prev = cur;
            cur = prev->next;
        }
        delete prev;
    }
}

string Movie::getDirectorName() {
    return directorName;
}

string Movie::getMovieTitle() {
    return movieTitle;
}

string Movie::getMovieTitleLower() {
    return movieTitleLower;
}

int Movie::getReleaseDay() {
    return releaseDay;
}

int Movie::getReleaseMonth() {
    return releaseMonth;
}

int Movie::getReleaseYear() {
    return releaseYear;
}


void Movie::getActors() {
    if (actorHead == NULL) {
        cout << "--none--" << endl;
    }
    else {
        ActorNode* temp = actorHead;
        while (temp != NULL) {
            cout << temp->actor.getName() << ", " << temp->actor.getRole() << endl;
            temp = temp->next;
        }
    }
}


string Movie::findActor(string actorName) {
    if (actorHead == NULL)
        return "";

    ActorNode* temp = actorHead;
    while (temp != NULL) {
        if (actorName == temp->actor.getNameLast()) {
            return temp->actor.getRole();
        }
        temp = temp->next;
    }
    return "";
}

void Movie::addActor(const string actorFirstName, const string actorLastName, const string actorRole) {
    // Create a new actor
    Actor actor(actorFirstName, actorLastName, actorRole);
    // Create a new actor node containing the new actor
    ActorNode* actorNode = new ActorNode;
    actorNode->actor = actor;
    actorNode->next = NULL;

    if (actorHead == NULL) { // NULL LIST
        actorHead = actorNode;
    }
    else if (actorHead->next == NULL) { // LIST WITH ONLY 1 ELEMENT
            int compareResult = actorHead->actor.getNameLast().compare(actorNode->actor.getNameLast());
            if (compareResult == 0) {
                cout << "Actor/Actress already exists." << endl;
            }
            else if (compareResult < 0) {
                actorHead->next = actorNode;
            }
            else {
                actorNode->next = actorHead;
                actorHead = actorNode;
            }
    }
    else { // LIST WITH 2 OR MORE ELEMENTS
        ActorNode* prev = actorHead;
        ActorNode* cur = actorHead->next;

        while(prev != NULL) {
            int comparePrev = prev->actor.getNameLast().compare(actorNode->actor.getNameLast());

            if (comparePrev == 0) {
                cout << "Actor already exists" << endl;
                break;
            }

            int compareCur = -987;
            if (cur != NULL)
                compareCur = cur->actor.getNameLast().compare(actorNode->actor.getNameLast());

            if (compareCur == 0) {
                cout << "Actor already exists" << endl;
                break;
            }

            if (comparePrev > 0) {
                actorNode->next = actorHead;
                actorHead = actorNode;
                break;
            }
            else if (comparePrev < 0 && cur == NULL) {
                prev->next = actorNode;
                break;
            }
            else if (comparePrev < 0 && compareCur > 0) {
                prev->next = actorNode;
                actorNode->next = cur;
                break;
            }
            else {
                prev = prev->next;
                cur = cur->next;
            }
        }
    }
}

void Movie::removeActor(string actorFirstName, string actorLastName) {
    if (actorHead == NULL) {
        cout << "Actor does not exist." << endl;
    }
    else {
        for (int i = 0; i < actorFirstName.length(); i++) {
            actorFirstName[i] = (char) tolower(actorFirstName[i]);
        }
        for (int j = 0; j < actorLastName.length(); j++) {
            actorLastName[j] = (char) tolower(actorLastName[j]);
        }
        string actorName = actorLastName + actorFirstName;

        if (actorHead->next == NULL) {
            if (actorHead->actor.getNameLast() == actorName) {
                actorHead = NULL;
            }
            else {
                cout << "Actor does not exist." << endl;
            }
        }
        else {
            ActorNode* prev = actorHead;
            ActorNode* cur = prev;

            while (cur != NULL) {
                if (cur->actor.getNameLast() == actorName) {
                    if (cur == prev) {
                        actorHead = actorHead->next;
                    }
                    else {
                        prev->next = cur->next;
                    }
                    delete cur;
                    break;
                }
                else {
                    if (cur == prev) {
                        cur = cur->next;
                    }
                    else {
                        cur = cur->next;
                        prev = prev->next;
                    }
                }
            }
        }
    }
}
