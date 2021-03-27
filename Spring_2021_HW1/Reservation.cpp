/**
 * Celal Berke Can
 * 21702886
 * Math
 * */

#include <iostream>
#include <string>
#include "Reservation.h"

using namespace std;

Reservation::Reservation(){
    seatChar = ' ';
    seatInt = 200;  // Impossible initiliazing.. 
    totalRes = 0;
};

Reservation::~Reservation() {
}

int Reservation::getResCode(){
    return resCode;
}

void Reservation::setResCode( int resCode){
    this->resCode = resCode;
}

void Reservation::setSeatChar( char col){
    this->seatChar = col;
}

char Reservation::getSeatChar(){
    return seatChar;
}

void Reservation::setSeatInt( int row){
    this->seatInt = row;
}

int Reservation::getSeatInt(){
    return seatInt;
}


// void Reservation::setSeat(const int row, const char col){
//     if ( seatChar == NULL && seatInt == NULL){
//         seatChar = new char[1];
//         seatInt = new int[1];

//         seatChar[totalRes] = col;
//         seatInt[totalRes] = row;

//         cout << "Reservation completed " << col << row << endl;

//         totalRes++;
//     }
//     else{
//         bool check = false;

//         for ( int i = 0; i < totalRes; i++){
//             if ( seatChar[i] == col && seatInt[i] == row)
//                 check = true;
//         } 

//         if( check){
//             cout << "not avaiable for reservation" << endl;
//         }
//         else
//         {
//             char* temp1 = seatChar;
//             seatChar = new char[totalRes +1 ];
//             int* temp2 = seatInt;
//             seatInt = new int[totalRes + 1];

//             for ( int i = 0; i < totalRes; i++){
//                 seatChar[i] = temp1[i];
//                 seatInt[i]  = temp2[i];
//             }

//             seatChar[totalRes] = col;
//             seatInt[totalRes] = row;

//             totalRes++;

//             cout << "Reservation completed " << col << row << endl;

//             delete temp1;
//             delete temp2;

//         }
//     }
// }