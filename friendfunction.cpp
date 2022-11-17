/* list of additional functions

borrow book
return book
operator >> for user & books
operator << for user & books
file input & output for user & book & record

print list of user borrowing the same book
print list of books borrowing by a user

*/

#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include "sach.h"
#include "user.h"
#include <iomanip>
#include <iostream>
using namespace std;

istream& operator >> (istream& inp, Sach &a) {
    cout<<"Nhap ten sach: ";
    getline(inp,a.tsach,'\n');
    cout<<"Nhap ten tac gia: ";
    getline(inp,a.ttgia,'\n');
    cout<<"Nhap so ban: ";
    inp>>a.soban;
    return inp;
}

ostream& operator << (ostream& out, const Sach &a) {
    out<<a.ma<<setw(40)<<a.tsach<<setw(40)<<a.ttgia<<setw(6)<<a.soban;
    return out;
}

istream& operator >> (istream& inp, User &a) {
    cout<<"Nhap ten nguoi dung: ";
    getline(inp,a.ten,'\n');
    cout<<"Nhap so CMND: ";
    inp>>a.cmd;
    return inp;
}

ostream& operator << (ostream& out, const User& a) {
    out<<a.uid<<setw(40)<<a.ten<<setw(16)<<a.uid;
    return out;
}

#endif