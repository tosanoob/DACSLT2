#ifndef SACH_H
#define SACH_H

#include <string>
#include "template.h"
using namespace std;

class Sach {
    private:
    string tsach, ttgia, ma;
    int soban;

    public:
    Sach(string,string,int);
    void update();
    bool operator == (const Sach&);
    void setid(const string&);
    string getid();
    ~Sach();

    friend istream& operator >> (istream&, Sach&);
    friend ostream& operator << (ostream&, const Sach&);
    
    friend void write_line(ofstream&, Node<Sach>&);
    friend void read_line(ifstream&, Node<Sach>&);
    friend void write_file(ofstream&, DSLK<Node<Sach>>&);
    friend void read_file(ifstream&, DSLK<Node<Sach>>&);
    /*
    friend functions:
    borrow books
    return books
    input book from keyboard (operator >>)
    output book to console (operator <<)
    print list of books borrowing by a user;
    print list of users borrowing the same book;
    input a list of books from file
    output a list of books to file
    */
    
};

#endif