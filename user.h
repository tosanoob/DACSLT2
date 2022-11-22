#ifndef USER_H
#define USER_H

#include <string>
#include "template.h"
#include "sach.h"
using namespace std;

class User
{
    string ten, cmd, uid;

    DSLK<Node<Sach*>> list;

public:
    User(string, string);
    void update();
    bool operator==(const User &);
    void setid(const string &);
    string getid();
    DSLK<Node<Sach*>>& getlist(); 
    ~User();

    friend istream &operator>>(istream &, User &);
    friend ostream &operator<<(ostream &, const User &);

    friend ifstream& operator >> (ifstream&, User&);
    friend ofstream& operator << (ofstream&, const User&);

    friend void write_file(ofstream&, DSLK<Node<User>>&);
    friend void read_file(ifstream&, DSLK<Node<User>>&);
    /*
    friend functions:
    borrow books
    return books
    print list of books borrowing by a user;
    print list of users borrowing the same book;
    input user from keyboard (operator >>)
    output user to console (operator <<)
    input a list of users from file
    output a list of users to file
    */
};

#endif
