/**
 * Celal Berke Can
 * 21702886
 * Math
 * */

#ifndef MOVIE_H
#define MOVIE_H

#include "Reservation.h"
#include<iostream>
#include<string>

using namespace std;

class Movie{
public:
    // Constructor
    Movie(long movieID, int audienceRadius);
    Movie();
    ~Movie();

    // Methods
    long getMovieID();
    void setMovieID( long movieID);

    void setAudienceRadius( int radius);
    int getAudienceRadius();

    void setTotalSeat();
    int getTotalSeat();

    int getNumRow();
    void setNumRow();

    int getNumCol();
    void setNumCol();

    char* getRowArr();
    void setRowArr();


    int* getColArr();
    void setColArr();

    void setTotalResevation( int numRes);
    void cancelReservation(int resCode);
    int getTotalReservation();

    bool makeReservationArr(const int row, const char col);
    Reservation* getReservationArr();

    void setDate();
    string getDate();   

    bool seatCheck(const int row, const char col); 
    
    char convertLetter( const int n);

private:
    long movieID;
    int audienceRadius;
    string date;
    
    // Calculate it in the constructor..
    int numRow;  //???
    int numCol;
    
    int totalSeat;
    int totalReservation;

    // ??????
    char* rowArr;
    int* columnArr;
    // column

    Reservation* reservationArr;

};

#endif //MOVIE_H