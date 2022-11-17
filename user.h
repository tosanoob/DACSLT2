#ifndef USER_H
#define USER_H

#include <string>
#include "template.h"
using namespace std;

class User
{
    string ten, cmd, uid;

public:
    User(string, string);
    void update();
    bool operator==(const User &);
    void setid(const string &);
    string getid();
    ~User();

    friend istream &operator>>(istream &, User &);
    friend ostream &operator<<(ostream &, const User &);

    friend void write_line(ofstream&, Node<User>&);
    friend void read_line(ifstream&, Node<User>&);
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
