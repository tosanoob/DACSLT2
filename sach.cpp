#ifndef SACH_CPP
#define SACH_CPP

#include "sach.h"
#include <iostream>

Sach::Sach(string ten="default", string tga="default", int cpy=0) : tsach(ten), ttgia(tga), soban(cpy), ma("000000") {}
void Sach::update()
{
    // cap nhat thong tin cua mot sach:
    cout << "Nhap moi thong tin cua cuon sach nay\n";
    cout << "Ten sach: ";
    cin.ignore();
    getline(cin, tsach, '\n');
    cout << "Ten tac gia: ";
    cin.ignore();
    getline(cin, ttgia, '\n');
    cout << "So ban in: ";
    cin >> soban;
    cout << "Cap nhat hoan tat";
    return;
}


void Sach:: setid(const string& a) {ma = a;}

string Sach:: getid() {return ma;}

bool Sach::operator==(const Sach &comp)
{
    if (tsach != comp.tsach)
        return 0;
    if (ttgia != comp.ttgia)
        return 0;
    return 1;
}
Sach::~Sach() {}

#endif