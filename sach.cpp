#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "base.h"
using namespace std;

istream &operator>>(istream &in, Sach &a)
{
    string ten, tga;
    int cpy;
    cout << "Nhap ten sach: ";
    getline(in, ten, '\n');
    cout << "Nhap ten tac gia: ";
    getline(in, tga, '\n');
    cout << "Nhap so ban: ";
    in >> cpy;
    a.settsach(ten);
    a.setttgia(tga);
    a.setsoban(cpy);
    return in;
}

ostream &operator<<(ostream &out, Sach a)
{
    out << a.ma;
    out << setw(40) << a.tsach << setw(30) << a.ttgia;
    out << setw(10) << a.soban << '\n';
    return out;
}
//-----------------------------------------------
int read_line(ifstream &inp, Sach &a)
{
    if (!inp)
    {
        cout << "Error input file";
        return 0;
    }
    string ten, tga, ma, cp;
    int cpy;
    getline(inp, ma, '|');
    if (ma.size() < 6)
        return 0;
    getline(inp, ten, '|');
    getline(inp, tga, '|');
    getline(inp, cp, '\n');
    cpy = stoi(cp);
    a.setma(ma);
    a.settsach(ten);
    a.setttgia(tga);
    a.setsoban(cpy);
    return 1;
}

int write_line(ofstream &out, Sach *a)
{
    if (!out)
    {
        cout << "Error output file";
        return 0;
    }
    out << a->ma << '|' << a->tsach << '|' << a->ttgia << '|' << a->soban << '\n';
    return 1;
}
//----------------------------------------------