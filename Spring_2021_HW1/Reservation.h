/**
 * Celal Berke Can
 * 21702886
 * Math
 * */

#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;


class Reservation{
public:
    // Constructor
    Reservation();
    ~Reservation();

    // Methods..
    int getResCode();
    void setResCode(int resCode);

    void setSeatChar(char col);
    char getSeatChar();

    void setSeatInt(int row);
    int getSeatInt();

    //void setSeat(const int row, const char col);
    
private:
    // Variables..

    int totalRes;
    int resCode;
    char seatChar;
    int seatInt;
};

#endif // RESERVATION_H