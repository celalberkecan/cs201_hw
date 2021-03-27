/**
 * Celal Berke Can
 * 21702886
 * Math
 * */

#ifndef MOVIEBOOKINGSYSTEM_H
#define MOVIEBOOKINGSYSTEM_H

#include "Movie.h"
#include "Reservation.h"
#include <iostream>
#include <string>

using namespace std;

class MovieBookingSystem{
public:
    const static int numOfRow = 30;
    const static int numOfColumn = 26;
    
    MovieBookingSystem();
    ~MovieBookingSystem();

    void addMovie( const long moiveID, const int audiencetRadius );
    void cancelMovie( const long movieID);
    void showAllMovies();
    void showMovie( const long movieID);
    int makeReservation( const long movieID, const int row, const char col);
    void cancelReservations( const int numRes, const int* resCode);
    void showReservation( const int resCode);

    int convertInt( const char chr);
    int resCodeGeneretor();

private:
    // Am Going to Add some private members..
    int sizeOfMovies;
    int initialResCode;
    Movie * arrayOfMovies;
};

#endif //MOVIEBOOKINGSYSTEM_H