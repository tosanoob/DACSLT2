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

#include "sach.cpp"
#include "user.cpp"
#include "template.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

//--------------Essential functions---------------
string increment(string & input) {
    int len = input.length()-1;
    for (int i = len; i>=0;i--) {
        if (input[i]=='9') {
            input[i]='0';
            continue;
        }
        input[i]+=1;
        break;
    }
    return input;
}

bool check_cmd(string & inp) {
    int len = inp.length()-1;
    for (int i=0;i<=len;i++) {
        if (inp[i]<'0' || inp[i]>'9') return 0;
    }
    return 1;
}

//------------Operator << >> for Sach------------

istream &operator>>(istream &inp, Sach &a)
{
    cout << "Nhap ten sach: ";
    inp.sync();
    getline(inp, a.tsach, '\n');
    cout << "Nhap ten tac gia: ";
    getline(inp, a.ttgia, '\n');
    cout << "Nhap so ban: ";
    inp >> a.soban;
    return inp;
}

ostream &operator<<(ostream &out, const Sach &a)
{
    out << a.ma << setw(40) << a.tsach << setw(40) << a.ttgia << setw(6) << a.soban;
    return out;
}

ofstream &operator<<(ofstream &out, Sach &a)
{
    out << a.ma << '|' << a.tsach << '|' << a.ttgia << '|' << a.soban << '\n';
    return out;
}

ifstream &operator>>(ifstream &inp, Sach &a)
{
    getline(inp, a.ma, '|');
    getline(inp, a.tsach, '|');
    getline(inp, a.ttgia, '|');
    string cp;
    getline(inp, cp, '\n');
    try {a.soban = stoi(cp);}
    catch (invalid_argument) {
        throw;
    }
    return inp;
}

//-------------Operator << >> for User------------


istream &operator>>(istream &inp, User &a)
{
    cout << "Nhap ten nguoi dung: ";
    inp.sync();
    getline(inp, a.ten, '\n');
    cout << "Nhap so CMND: ";
    bool flag;
    do 
    {
        inp >> a.cmd;    
        flag = check_cmd(a.cmd);
        if (!flag) {
            cout<<"So CMND gom 9 ki tu so, vui long nhap lai: "; 
        }
    } while (!flag);
    return inp;
}

ostream &operator<<(ostream &out, const User &a)
{
    out << a.uid << setw(40) << a.ten << setw(16) << a.cmd;
    return out;
}

ifstream &operator>>(ifstream &inp, User &a)
{
    getline(inp, a.uid, '|');
    getline(inp, a.ten, '|');
    getline(inp, a.cmd, '\n');
    return inp;
}

ofstream &operator<<(ofstream &out, User &user)
{
    out << user.uid << '|' << user.ten << '|' << user.cmd << '\n';
}

//-------------Readfile & Writefile---------
void read_file(ifstream &inp, DSLK<Node<Sach>> &list)
{
    Sach temp;
    while (!inp.eof())
    {
        try {inp >> temp;}
        catch (invalid_argument) {
            return;
        }
        list.insert(temp);
    }
    return;
}

void read_file(ifstream &inp, DSLK<Node<User>> &list)
{
    User temp;
    while (!inp.eof())
    {
        inp >> temp;
        list.insert(temp);
    }
    return;
}


void write_file(ofstream &out, DSLK<Node<User>> &list)
{
    Node<User>* temp = list.head;
    for (int i =0;i<list.size;i++) {
        out<<temp->getdata();
        temp=temp->tonext();
    }
}

void write_file(ofstream &out, DSLK<Node<Sach>> &list)
{
    Node<Sach>* temp = list.head;
    for (int i =0;i<list.size;i++) {
        out<<temp->getdata();
        temp=temp->tonext();
    }
}

//------------Find & Borrow & Return------------

Sach& find_id (const string & lookid, DSLK<Node<Sach>>& list) {
    Node<Sach>* temp = list.head;
    for (int i =0;i<list.size;i++) {
        if (temp->getdata().getid()==lookid) return temp->getdata();
        temp = temp->tonext();
    }
    if (temp==NULL) throw MEMBER_NOTFOUND;
}

User& find_id (const string & lookid, DSLK<Node<User>>& list) {
    Node<User>* temp = list.head;
    for (int i =0;i<list.size;i++) {
        if (temp->getdata().getid()==lookid) return temp->getdata();
        temp = temp->tonext();
    }
    if (temp==NULL) throw MEMBER_NOTFOUND;
}

bool borrowbook(User& borrower, Sach& target) {
    if (target.soban==0) return 0; 
    User* borrower_ptr = &borrower;
    Sach* target_ptr = &target;
    borrower.getlist().insert(target_ptr);
    target.getlist().insert(borrower_ptr);
    target.soban--;
    cout<<"function borrow succeed\n";
    return 1;
}

bool returnbook(User& borrower, Sach& target) {
    User* borrower_ptr = &borrower;
    Sach* target_ptr = &target;
    borrower.getlist().remove(target_ptr);
    target.getlist().remove(borrower_ptr);
    target.soban++;
    cout<<"function return succeed\n";
    return 1;
}

#endif