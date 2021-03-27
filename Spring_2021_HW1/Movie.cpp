/**
 * Celal Berke Can
 * 21702886
 * Math
 * */

#include <iostream>
#include <string>
#include <ctime>
#include "Movie.h"
#include "MovieBookingSystem.h"

using namespace std;

Movie::Movie(long movieID,  int audienceRadius){
    this->movieID = movieID;
    this->audienceRadius = audienceRadius;
	reservationArr = NULL;
	totalReservation = 0;
	// Calculate total seat of theather.. with radius
	totalSeat = numRow * numCol;


    // Calcuale neseccary values for theather..
    numRow = 0;
    numCol = 0;

    for ( int i = 1; i <= 26; i = i+ (audienceRadius + 1)){
        numRow++;
    }

	for ( int i = 1; i <= 30; i = i+ (audienceRadius + 1)){    
        numCol++;
    }


	//Create the first column and first row arrays..

	rowArr =  new char[numRow-1];
	columnArr = new int[numCol];

	int x = 0;
	for ( int i = 1; i <= 26; i = i+ (audienceRadius + 1)){
        rowArr[x] = convertLetter(i);
		x++;
    }

	int y = 0;
	for ( int i = 1; i <= 30; i = i+ (audienceRadius + 1)){    
        columnArr[y] =  i;
		y++;
    }
}

Movie::Movie(){
	movieID = 0;
	audienceRadius = 0;
	numRow = 0;
	numCol = 0;
	totalSeat = 0;
	totalReservation = 0;
	rowArr = NULL;
	columnArr = NULL;
	reservationArr = NULL;

	
	date =" ";
}

Movie::~Movie(){

	delete[] reservationArr;
	delete[] rowArr;
	delete[] columnArr;
	//cout << "Destructor for movie!!!" << endl;
}

void Movie::setMovieID( long movieID){
	this->movieID =  movieID;
}

long Movie::getMovieID(){
	return this->movieID;
}

void Movie::setAudienceRadius(int radius){
	this->audienceRadius = radius;
}

int Movie::getAudienceRadius(){
	return this->audienceRadius;
}

void Movie::setDate( ){

	char* time = ctime(&movieID);

    //string time = timex.substr(0, timex.length() - 1);
	
	date = time;
}

string Movie::getDate(){
	return this->date;
}

int Movie::getTotalSeat(){
	return numRow * numCol;
}

void Movie::setNumRow(){
	for ( int i = 1; i <= 26; i = i+ (audienceRadius + 1)){
        numRow++;
    }
}
int Movie::getNumRow(){
	return this->numRow;
}

void Movie::setNumCol(){
	for ( int i = 1; i <= 30; i = i+ (audienceRadius + 1)){    
        numCol++;
    }
}
int Movie::getNumCol(){
	return numCol;
}

void Movie::setRowArr(){
	rowArr =  new char[numRow];
	int x = 0;
	for ( int i = 1; i <= 26; i = i+ (audienceRadius + 1)){
        rowArr[x] = convertLetter(i);
		x++;
    }	
}

char* Movie::getRowArr(){
	return this->rowArr;
}

void Movie::setColArr(){
	columnArr = new int[numCol];
	int y = 0;
	for ( int i = 1; i <= 30; i = i+ (audienceRadius + 1)){    
        columnArr[y] =  i;
		y++;
    }

}
int* Movie::getColArr(){
	return this->columnArr;
}

int Movie::getTotalReservation(){
	return this->totalReservation;
}

bool Movie::seatCheck(const int row, const char col){
	bool check = false;

	for( int i = 0; i < totalReservation; i++){
		if (reservationArr[i].getSeatChar() == col && reservationArr[i].getSeatInt() == row){
			check = true;
			return check;
		}
	}
	return check;
}

bool Movie::makeReservationArr(const int row, const char col){
	bool boo = true;
	if ( reservationArr == NULL){
		reservationArr = new Reservation[1];
		reservationArr[totalReservation].setSeatChar(col);
		reservationArr[totalReservation].setSeatInt(row);

		totalReservation++;
		//cout << "Reservation done " << col << row ; 
	}
	else
	{
		bool check = seatCheck(row, col);
		if ( check){
			cout << "Seat " << col << row << " is not available in Movie at " << getDate() << endl; 
			boo = false;
			return boo;
		}
		else
		{
			Reservation*  temp = reservationArr;
			reservationArr = new Reservation[totalReservation + 1];

			for ( int i = 0; i < totalReservation; i++){
				reservationArr[i].setSeatChar(temp[i].getSeatChar());
				reservationArr[i].setSeatInt(temp[i].getSeatInt());
				reservationArr[i].setResCode(temp[i].getResCode());

			}

			reservationArr[totalReservation].setSeatChar(col);
			reservationArr[totalReservation].setSeatInt(row);
			//reservationArr[totalReservation].setSeatInt(row);


			totalReservation++;

			//cout << "Reservation done " << col << row << endl; 

			delete[] temp;
		}
	}
	return boo;
}

void Movie::cancelReservation(int resCode){
	int index = 0; 
	for ( int i = 0;  i < totalReservation; i++){
		if ( reservationArr[i].getResCode() == resCode){
			index = i;
		}
	}

	Reservation* temp = reservationArr;
	reservationArr = new Reservation[totalReservation - 1];
	for ( int i = 0; i < index; i++){
		reservationArr[i].setSeatChar(temp[i].getSeatChar());
		reservationArr[i].setSeatInt(temp[i].getSeatInt());
		reservationArr[i].setResCode(temp[i].getResCode());

	}

	for ( int i = index + 1; i < totalReservation; i++){
		reservationArr[i-1].setSeatChar(temp[i].getSeatChar());
		reservationArr[i-1].setSeatInt(temp[i].getSeatInt());
		reservationArr[i-1].setResCode(temp[i].getResCode());

	}

	totalReservation--;
	delete[] temp;
}

Reservation* Movie::getReservationArr(){
	return this->reservationArr;
}

char Movie::convertLetter( const int n){
    if ( n >= 1 && n <= 26)
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n - 1];
    return '-';
}

