#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "base.h"
#include "sach.cpp"
using namespace std;

//--------------------------------------------------
int User::muonsach(Sach *a, DSSach &lib) // con tro a tro vao danh sach thu vien
{
    if (a->getsoban() == 0)
    {
        cout << "Khong con ban nao, khong the muon\n";
        return 0;
    }
    if (head == NULL)
    {   
        cout<<"gethere0\n";
        Sach* temp = new Sach(*a); // tao doi tuong sao chep sang ds rieng cua nguoi dung
        cout<<"gethere1\n";
        head = temp;
        tail = temp;
        temp->set_next(NULL);
        temp->set_prev(NULL);
        temp->setsoban(0);
        soluong++;
        a->giam1();
    }
    else
    {
        this->push(*a);
        soluong++;
        a->giam1();
    }
    return 1;
}

int User::trasach(Sach *a, DSSach &lib) // con tro a tro vao sach trong thu vien rieng cua nguoi dung
{
    string ma = a->getma();
    Sach *tar = lib.searchma(ma);
    this->del_sach(a);
    tar->tang1();
    this->soluong--;
    return 1;
}

//--------------------------------------------------
istream &operator>>(istream &in, User &a)
{
    cout << "Nhap ten nguoi dung: ";
    getline(in, a.ten, '\n');
    cout << "Nhap so CMND: ";
    in >> a.cmd;
    return in;
}

ostream &operator<<(ostream &out, User a)
{
    out << a.uid << setw(40) << a.ten << setw(15) << a.cmd << '\n';
    return out;
}
//--------------------------------------------------
// uid|ten|cmd|sl\n
// n dong, moi dong co dinh dang giong trong file sach
int read_user(ifstream &inp, User &a)
{
    if (!inp)
    {
        cout << "Error input file";
        return 0;
    }
    if (a.gethead() != NULL)
    {   //xoa list dang co cua a
        Sach *temp = a.gethead(), *pretemp = a.gethead();
        for (int i = 0; i < a.getsl(); i++)
        {
            temp = temp->to_next();
            delete pretemp;
            pretemp = temp;
        }
    }
    string ten, cmd, uid, slg;
    int sl;
    getline(inp, uid, '|');
    getline(inp, ten, '|');
    getline(inp, cmd, '|');
    getline(inp, slg, '\n');
    sl = stoi(slg);
    a.setuid(uid);
    a.setten(ten);
    a.setcmd(cmd);
    int check = 1;
    Sach b;
    if (sl >= 1)
    {
        check = read_line(inp, b);
        if (check == 0)
            return 0;
        Sach *temp = new Sach(b);
        a.head = temp;
        a.tail = temp;
        a.soluong++;
    }
    if (sl >= 2)
    {
        for (int i = 2; i <= sl; i++)
        {
            read_line(inp, b);
            a.push(b);
        }
    }
    return 1;
}

int write_user(ofstream &out, User *a)
{
    if (!out)
    {
        cout << "Error output file";
        return 0;
    }
    out << a->uid << '|' << a->ten << '|' << a->cmd <<'|'<< a->soluong << '\n';
    write_file(out, a);
    return 1;
}

User::~User()
{
    next = NULL;
    prev = NULL;
}