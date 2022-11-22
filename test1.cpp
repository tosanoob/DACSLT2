#include <iostream>
#include "sach.cpp"
#include "user.cpp"
#include "template.cpp"
#include "friendfunction.cpp"
using namespace std;

int main() {
    ifstream inp_user("userbase.txt");
    ifstream inp_sach("sachbase.txt");

    DSLK<Node<Sach>> sachlist;
    DSLK<Node<User>> userlist;
    try {
    read_file(inp_user,userlist);
    read_file(inp_sach,sachlist);
     }
    catch (invalid_argument) {
        cout<<"invalid_argument ocurred";
        return 0;
    }
        sachlist.display();

        cout<<"display1 passed\n";

        userlist.display();

        cout<<"display2 passed\n";
   
    inp_user.close();
    inp_sach.close();

    ofstream out_user("userbase.txt");
    ofstream out_sach("sachbase.txt");
    write_file(out_sach,sachlist);
    write_file(out_user,userlist);
    cout<<"writefile success\n";
    return 1;
}