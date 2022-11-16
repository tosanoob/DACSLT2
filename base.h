// This header include 4 basic class of data:
//       class Sach for storing book information;
//       class DSSach for storing list of books;
//       class User for storing user information and borrowed books;
//       class DSUser for storing list of users;

#pragma once
#include <string>
using namespace std;

string incre(string a) {
    int size=a.size();
    for (int i=size-1;i>=0;i--) {
        if (a[i]=='9')  {
            a[i]='0';
            continue;
        }
        a[i]+=1;
        break;
    }
    return a;
}
//-----------------------------------------------------
class Sach
{
    // Storing book information, node of a doubly-linked list;
    string tsach = "default", ttgia = "default", ma = "000000";
    int soban = 0;

    Sach *prev = NULL;
    Sach *next = NULL;

public:
    // Constructor
    Sach() {}
    Sach(string ten, string tga, int cpy) : tsach(ten), ttgia(tga), soban(cpy) {}
    Sach(const Sach &a) : tsach(a.tsach), ttgia(a.ttgia), soban(a.soban), ma(a.ma)
    {
        prev = NULL;
        next = NULL;
    }
    // getter&setter
    string gettsach() { return tsach; }
    string getttgia() { return ttgia; }
    string getma() { return ma; }
    int getsoban() { return soban; }
    Sach *to_next() { return next; }
    Sach *to_prev() { return prev; }
    void settsach(string ten) { tsach = ten; }
    void setttgia(string t) { ttgia = t; }
    void setma(string m) { ma = m; }
    void setsoban(int c) { soban = c; }
    void set_next(Sach *a) { next = a; }
    void set_prev(Sach *a) { prev = a; }
    void giam1() {soban--;}
    void tang1() {soban++;}
    // nhap/xuat sach qua man hinh
    friend istream &operator>>(istream &in, Sach &a);  // nhập từ màn hình không nhập mã, mã tự tạo
    friend ostream &operator<<(ostream &out, Sach a); // xuất danh sách có bao gồm mã
    // nhap/xuat sach qua file
    friend int read_line(ifstream &inp, Sach &a);  // có nhập mã
    friend int write_line(ofstream &out, Sach *a); // có xuất mã
    ~Sach(){
        prev=NULL;
        next=NULL;
    }
};
//----------------------------------
class DSSach
{
    // Storing a doubly-linked list of Sach;
protected:
    Sach *head = NULL;
    Sach *tail = NULL;
    int soluong = 0;

public:
    // Constructor
    DSSach() {}
    // getter&setter
    Sach *gethead() { return head; }
    Sach *gettail() { return tail; }
    int getsl() { return soluong; }
    void sethead(Sach *a) { head = a; }
    void settail(Sach *a) { tail = a; }
    void setsl(int a) { soluong = a; }
    // them 1 sach vao cuoi danh sach
    Sach *push(Sach a);                          // dùng khi đọc từ file, copy object push vào đuôi, trả về đuôi danh sách
    Sach *push(string ten, string tga, int cpy); // dùng khi nhập thủ công từ màn hình, không nhập mã, trả về đuôi danh sách
    // xoa mot sach bat ki trong danh sach
    bool del_sach(Sach *a); // xoá thành công trả về 1, xoá thất bại trả về 0;
    // tim mot sach co ten "string" trong danh sach, tra ve con tro
    Sach* find_duplicate(string tsach, string ttgia);
    Sach *searchname(string ten);
    Sach *searchma(string ma);
    // xuat danh sach qua man hinh: in ra tối đa 20 sách tính từ Sach* start, trả về con trỏ trỏ tới cuốn thứ 21 hoặc NULL
    Sach *display(Sach *start);
    // nhap/xuat danh sach sach qua file
    friend class Sach;
    friend int read_file(ifstream &inp, DSSach &lib);
    friend int write_file(ofstream &out, DSSach *lib);
    // destructor: xoá danh sách
    virtual ~DSSach();
};
//-----------------------------------
class User : public DSSach
{
    // mỗi user có 1 danh sách sách mượn, kèm theo thông tin họ tên, cmnd, mã user;
    // mỗi user cũng là 1 node trong ds liên kết đôi
    string ten = "default";
    string cmd = "100000000";
    string uid = "00000";

    User *next = NULL;
    User *prev = NULL;

public:
    // constructor
    User():DSSach(){}
    User(string ten, string cmd) : ten(ten),cmd(cmd){}
    User(const User &a) : ten(a.ten), cmd(a.cmd), uid(a.uid){
        next=NULL;
        prev=NULL;
        Sach* temp = a.head;
        while (temp!=NULL) {
            Sach* newtemp = new Sach(*temp);
            if (head==NULL) {
                head=newtemp;
                tail=newtemp;
                newtemp->set_next(NULL);
                newtemp->set_prev(NULL);
                soluong++;
            }
            else {
                newtemp->set_prev(tail);
                tail->set_next(newtemp);
                tail=newtemp;
                soluong++;
            }
            temp=temp->to_next();
        }
    }
    // getter&setter
    string getten() { return ten; }
    string getcmd() { return cmd; }
    string getuid() { return uid; }
    User *to_next() { return next; }
    User *to_prev() { return prev; }
    void setten(string t) { ten=t; }
    void setcmd(string c) { cmd=c; }
    void setuid(string u) {uid =u;}
    void set_next(User *a) { next = a; }
    void set_prev(User *a) { prev = a; }

    int muonsach(Sach* a, DSSach &lib); //mượn sách được trỏ bởi con trỏ a, từ danh sách thư viện lib;
    int trasach(Sach* a, DSSach &lib);  //trả sách được trỏ bởi con trỏ a, trả về danh sách thư viện lib;0    
    
    // nhập/xuất người dùng ra màn hình
    friend istream &operator>>(istream &in, User &a);
    friend ostream &operator<<(ostream &out, User a);
    // nhập/xuất người dùng qua file trên 1 dòng
    friend int read_user (ifstream &inp, User &a);
    friend int write_user(ofstream &out, User *a);
    ~User();
};

class DSUser {
    User* head=NULL;
    User* tail =NULL;
    int soluong =0;

    public:
    //constructor
    DSUser(){}
    //getter&Setter
    User *gethead() { return head; }
    User *gettail() { return tail; }
    int getsl() { return soluong; }
    void sethead(User *a) { head = a; }
    void settail(User *a) { tail = a; }
    void setsl(int a) { soluong = a; }
    //thêm 1 user vào cuối danh sách
    User *push(User a); //dùng khi đọc từ file, copy object push vào danh sách
    User *push(string ten, string cmd); //dùng khi nhập từ bàn phím
    //xoá 1 user bất kì trong danh sách
    bool del_user(User *a);
    //tìm user theo tên, trả về con trỏ
    DSUser* searchlistname(string ten);
    User* searchname(string ten); //return 1 danh sach?
    User* searchuid(string uid);
    User* searchcmd(string cmd);
    //xuất danh sách qua màn hình, hiển thị 20 người dùng từ start
    User* display(User * start);
    //nhập, xuất danh sách qua file;
    friend class User;
    friend int read_file (ifstream &inp, DSUser &lib);
    friend int write_file(ofstream &out, DSUser &lib);
    //destructor: duyệt và xoá danh sách
    ~DSUser();
};
