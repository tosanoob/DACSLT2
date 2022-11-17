#ifndef RECORD_H
#define RECORD_H

#include "template.h"
#include "user.h"
#include "sach.h"

class Record {
    private:
    Node<User>* user;
    Node<Sach>* sach;

    public:
    Record();
    Record(User&,Sach&);
    void update();
    bool operator == (const Record&);
    ~Record();

    /*
    friend functions:
    borrow books
    return books
    print list of books borrowing by a user;
    print list of users borrowing the same book;
    input a list of records from file
    output a list of records to file
    */
};

#endif