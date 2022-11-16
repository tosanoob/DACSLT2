#ifndef SACH_H
#define SACH_H

#include "template.h"
#include <string>
using namespace std;

class Sach {
    private:
    string tsach, ttgia, ma;
    int soban;

    public:
    Sach();
    Sach(string,string,int);
    Sach(const Sach&);
    void update();
    bool operator == (const Sach&);
    ~Sach();

    //friend functions
    //borrow books
    //return books
    //input book from keyboard (operator >>)
    //output book to console (operator <<)
    //input a list of books to file
    //output a list of books to file
};

#endif