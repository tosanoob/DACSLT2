#include "template.cpp"
#include <iostream>
using namespace std;

class Num {
    int num;

    public:
    Num(int n) : num(n) {}
    Num(const Num& a) : num(a.num) {}
    bool operator == (const Num& comp) {
        return (num==comp.num);
    }
    void update() {
        cin>>num;
        cout<<"updated\n";
    }
    void setnum(int n) {
        num=n;
    }
    friend ostream& operator << (ostream& out, const Num& o);
    ~Num(){}
};

ostream& operator << (ostream& out, const Num& o) {
    cout<<o.num;
}

int main() {
    Node<Num> a(Num(5));
    DSLK<Node<Num>> handle;
    handle.insert(a);
    a.getdata().setnum(10);
    handle.insert(a);
    a.getdata().setnum(11);
    handle.insert(a);
    a.getdata().setnum(16);
    handle.insert(a);
    handle.update(a);
    handle.display();
    return 0;
}