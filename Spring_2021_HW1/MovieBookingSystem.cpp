/**
 * Celal Berke Can
 * 21702886
 * Math
 * */

#include<iostream>
#include<string>
#include <ctime>

#include "MovieBookingSystem.h"

using namespace std;

// Constuctor...
MovieBookingSystem::MovieBookingSystem(){
    sizeOfMovies = 0;
    arrayOfMovies = NULL;
    initialResCode = 0;
}

// Destructor...
MovieBookingSystem::~MovieBookingSystem(){
    // delete the main array..
    delete[] arrayOfMovies;
}

// Methods...

/**
 * ADD MOVIE..
 * */
void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius){
    bool radiusCheck = false;

    // Radis check..
    if( 0 <= audienceRadius && audienceRadius <= 7){
        radiusCheck = true;
    }
    
    // Add first element of movie array..
    if(radiusCheck){
        if (arrayOfMovies == NULL){
            
            arrayOfMovies = new Movie[1];
            arrayOfMovies[sizeOfMovies].setMovieID(movieID);
            arrayOfMovies[sizeOfMovies].setAudienceRadius(audienceRadius);
            arrayOfMovies[sizeOfMovies].setNumCol();
            arrayOfMovies[sizeOfMovies].setNumRow();
            arrayOfMovies[sizeOfMovies].setRowArr();
            arrayOfMovies[sizeOfMovies].setColArr();
            arrayOfMovies[sizeOfMovies].setDate();
            
            
            cout << "Movie at " << arrayOfMovies[sizeOfMovies ].getDate() <<" has been added" << endl;
            
            sizeOfMovies++;
        }
        else{
            // checking that movie exists or not..
            bool check = false;
            int index = 0;

            for ( int i = 0; i < sizeOfMovies; i++){
                if ( arrayOfMovies[i].getMovieID() == movieID)
                    check =  true;
            }

            // Warning Message Already Exists..
            if ( check){
                cout << "Moive at " << arrayOfMovies[index].getDate() <<" already exists" << endl;
            }

            else{
                //Movie is unique increse size of array 1 and add the movie in the end..
                Movie* temp = arrayOfMovies;
                arrayOfMovies = new Movie[sizeOfMovies + 1];

                for ( int i = 0; i < sizeOfMovies; i++){
                    //arrayOfMovies[i] = temp[i];
                    arrayOfMovies[i ].setMovieID(temp[i].getMovieID()); 
                    arrayOfMovies[i ].setAudienceRadius(temp[i].getAudienceRadius());
                    arrayOfMovies[i ].setNumCol();
                    arrayOfMovies[i ].setNumRow();
                    arrayOfMovies[i ].setRowArr();
                    arrayOfMovies[i ].setColArr();
                    arrayOfMovies[i ].setDate();
                }

                arrayOfMovies[sizeOfMovies ].setMovieID(movieID);
                arrayOfMovies[sizeOfMovies ].setAudienceRadius(audienceRadius);
                arrayOfMovies[sizeOfMovies ].setNumCol();
                arrayOfMovies[sizeOfMovies ].setNumRow();
                arrayOfMovies[sizeOfMovies ].setRowArr();
                arrayOfMovies[sizeOfMovies ].setColArr();
                arrayOfMovies[sizeOfMovies ].setDate();
                
                cout << "Movie at " << arrayOfMovies[sizeOfMovies ].getDate() << " has been added" << endl;
                sizeOfMovies++;

                delete[] temp;
            }
        }
    }
    else{
        cout << "Invalid radius for a movie" << endl;
    }
}

/**
 * CANCEL MOVIE
 * Deletes given movie if the movie exist and decrese size by 1...
 * */
void MovieBookingSystem::cancelMovie(const long movieID){
    bool check = false;
    int index = 0;

    for ( int i = 0; i < sizeOfMovies; i++){
        if ( arrayOfMovies[i].getMovieID() == movieID){
            check = true;
            index = i;
        }
    }

    if ( check){

        Movie* temp = arrayOfMovies;
        arrayOfMovies = new Movie[sizeOfMovies - 1];

        for ( int i = 0; i < index; i++){
            arrayOfMovies[i ].setMovieID(temp[i].getMovieID()); 
            arrayOfMovies[i ].setAudienceRadius(temp[i].getAudienceRadius());
            arrayOfMovies[i ].setNumCol();
            arrayOfMovies[i ].setNumRow();
            arrayOfMovies[i ].setRowArr();
            arrayOfMovies[i ].setColArr();
            arrayOfMovies[i ].setDate();
        }

        for ( int i = index + 1 ; i < sizeOfMovies; i++){
            arrayOfMovies[i - 1 ].setMovieID(temp[i].getMovieID()); 
            arrayOfMovies[i - 1 ].setAudienceRadius(temp[i].getAudienceRadius());
            arrayOfMovies[i - 1 ].setNumCol();
            arrayOfMovies[i - 1 ].setNumRow();
            arrayOfMovies[i - 1 ].setRowArr();
            arrayOfMovies[i - 1 ].setColArr();
            arrayOfMovies[i - 1 ].setDate();
        }

        /**
         *  
         * ATTENTION DO NOT FORGET
         * 
         * */
        // Reservations must also be deleted....  ?????
        delete[] arrayOfMovies[index].getReservationArr();

        cout << "Movie at " << arrayOfMovies[index].getDate() <<" has been canceled" << endl;
        sizeOfMovies--;

        delete[] temp;
    }
    else{
        char* time = ctime(&movieID);
        cout << "Movie "<< time <<" does not exists" << endl;
    }
}

/**
 * SHOW ALL MOVIES
 * Shows the all movies..
 * */
void MovieBookingSystem::showAllMovies(){
    if ( sizeOfMovies == 0) { cout << "No movie on show" << endl;}

    else{
        cout << "Movies on show:" << endl;
        for ( int i = 0; i < sizeOfMovies; i++){
            cout << "Movie at " << arrayOfMovies[i].getDate() <<" (" << arrayOfMovies[i].getTotalSeat() - arrayOfMovies[i].getTotalReservation() << " available seats)" << endl;
        }
    }
}

/**
 * SHOW MOVIE
 * show the movie with given ıd in details..
 * */
void MovieBookingSystem::showMovie( const long movieID){
    bool check = false;
    int index = 0;
     

    for ( int i = 0; i < sizeOfMovies; i++){
        if ( arrayOfMovies[i].getMovieID() == movieID){
            check = true;
            index = i;
        }
    }

    if( check){
        cout << "Movie at " << arrayOfMovies[index].getDate() << " has " << arrayOfMovies[index].getTotalSeat() - arrayOfMovies[index].getTotalReservation() << " available seats" << endl;
        int resNum = arrayOfMovies[index].getTotalReservation();
        int*  resCol = new int[resNum];
        
        for ( int j = 0; j < arrayOfMovies[index].getNumRow() + 1; j++){
            if ( j == 0 ){
                cout <<"    ";
            }
            else{
                cout << arrayOfMovies[index].getRowArr()[j-1] << "  ";
                for ( int i = 0; i < resNum; i++){
                    if ( arrayOfMovies[index].getRowArr()[j-1] == arrayOfMovies[index].getReservationArr()[i].getSeatChar() ){
                        resCol[i] = j - 1;
                    }
                }
            }
        }

        cout << endl;

        bool boo = false;
        int* resRow = new int [resNum];
        for ( int i = 0; i < resNum; i++){
            resRow[i] = 100;                          // To Fix the bug initilaze with a impossible value....
        }

        for ( int k = 0; k < arrayOfMovies[index].getNumCol(); k++){
            for ( int t = 0; t < resNum; t++){
                if ( arrayOfMovies[index].getColArr()[k] == arrayOfMovies[index].getReservationArr()[t].getSeatInt() ){
                    resRow[t] = k;
                }
            }
            if ( arrayOfMovies[index].getColArr()[k] < 10){
                cout << " " << arrayOfMovies[index].getColArr()[k] << "  ";
            }
            else{
                cout << arrayOfMovies[index].getColArr()[k] << "  ";
            }
            for ( int m = 0; m < arrayOfMovies[index].getNumRow(); m++){
                for ( int z = 0; z < resNum; z++){
                    if ( k == resRow[z] && m == resCol[z])
                        boo = true;
                }
                if (boo)
                    cout << "x  ";
                else
                    cout << "o  ";
                boo = false;
            }
            cout << endl;
        }

        delete[] resRow;
        delete[] resCol;

    }
    else{
        char* time = ctime(&movieID);
        cout << "Movie " << time << "does not exists" << endl;
    }
}

/**
 * MAKE RESERVATION..
 * makes the reservation with given ıd and seat variables..
 * */
int MovieBookingSystem::makeReservation( const long movieID, const int row, const char col){
    bool check = false;
    int index = 0;
    int resCode = 0;
    int in = 0;

    for ( int i = 0; i < sizeOfMovies; i++){
        if ( arrayOfMovies[i].getMovieID() == movieID){
            check = true;
            index = i;
        }
    }

    if ( check){
        if ( row % (arrayOfMovies[index].getAudienceRadius() + 1) == 1 && convertInt(col) % (arrayOfMovies[index].getAudienceRadius() + 1) == 1){
            bool boo = arrayOfMovies[index].seatCheck(row, col);
            
            if(arrayOfMovies[index].makeReservationArr(row, col)){
                in = arrayOfMovies[index].getTotalReservation();
                int resCode = resCodeGeneretor(); 
                arrayOfMovies[index].getReservationArr()[in - 1].setResCode(resCode);    
            
                cout << "Reservation done " << col << row <<" in Movie at "<<arrayOfMovies[index].getDate() << endl;                
                return resCode;    
        
            }
        }
        else{
            cout << "Seat " << col << row << " is not occupiable in Movie at " << arrayOfMovies[index].getDate() << endl; 
        }    

    }
    else{
        cout << "Movie " << movieID << " does not exists. (reservation)" << endl;
    }
    return -1; // implies error..
}

/**
 * CANCEL RESEVATION
 * 
 * */
void MovieBookingSystem::cancelReservations( const int numRes, const int* resCode){
    bool check = false;
    int* isCorrect = new int[numRes];

    for ( int i = 0; i < numRes; i++){
        isCorrect[i] = 0;                       // In order to prevent conditional jump initilialised with some value...!!!!!
    }
     
    char col = ' ';
    int row = 0;
    for ( int i = 0; i < numRes; i++){
        for ( int j = 0; j < sizeOfMovies; j++){
            for ( int k = 0; k < arrayOfMovies[j].getTotalReservation(); k++){
                if ( arrayOfMovies[j].getReservationArr()[k].getResCode() == resCode[i]){
                    isCorrect[i] = resCode[i];
                }
            }
        }
    }

    for (int i = 0; i < numRes; i++){
        if ( isCorrect[i] == resCode[i]){
            check = true;
        }
        else
        {
            check = false;
        }
    }

    if ( check){
        for ( int i = 0; i < numRes; i++){
            for ( int j = 0; j < sizeOfMovies; j++){
                for ( int k = 0; k < arrayOfMovies[j].getTotalReservation(); k++){
                    if ( arrayOfMovies[j].getReservationArr()[k].getResCode() == resCode[i]){
                        col = arrayOfMovies[j].getReservationArr()[k].getSeatChar();
                        row = arrayOfMovies[j].getReservationArr()[k].getSeatInt();
                        arrayOfMovies[j].cancelReservation(resCode[i]);
                        cout <<"Reservation on Code " << resCode[i] << " is canceled: Seat " << col << row <<" in Movie at " << arrayOfMovies[j].getDate() << endl;
                        char col = ' ';
                        int row = 0;
                }
            }
        }
    } 
    }
    else{
    cout << "Some reservation codes do not exists. Cancelation is failed" << endl;

    }
    
    delete[] isCorrect;
}

/**
 * SHOW RESERVATION ..
 * */
void MovieBookingSystem::showReservation( const int resCode){
    bool boo = false;
    for ( int i = 0; i < sizeOfMovies; i++){
        for ( int j = 0; j < arrayOfMovies[i].getTotalReservation(); j++){
            if ( arrayOfMovies[i].getReservationArr()[j].getResCode() == resCode){
                cout << "Reservation with Code " << resCode << ": Seat " << arrayOfMovies[i].getReservationArr()[j].getSeatChar() << arrayOfMovies[i].getReservationArr()[j].getSeatInt() << " Movie at "<< arrayOfMovies[i].getDate() << endl;
                boo = true;
            }    
        }
    }
    if(!boo){
        cout << "No reservation with Code " << resCode << endl;
    }
}

/**
 * RES CODE GENERETOR
 * generates unique codes for entire system..
 * */
int MovieBookingSystem::resCodeGeneretor(){
    initialResCode = initialResCode + 1;
    return initialResCode;
}

int MovieBookingSystem::convertInt(const char chr){
    return (chr - 'A') + 1;
}