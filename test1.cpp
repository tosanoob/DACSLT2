#include <iostream>
using namespace std;

class Obj {
    public:
    template <class T> 
    void print(T){};
    template <class T>
    void echo(T){};
};

class Objint : public Obj {
    public:
    void print(int a) {
        cout<<a<<'\n';
    }
    void echo(int a) {
        cout<<"Hello, i put: "<<a<<'\n';
    }
};

int main() {
    Objint x;
    Obj* ptr;
    ptr->print(5);
    ptr->echo(6);
}