#include <iostream>
#include "sach.cpp"
#include "user.cpp"
#include "template.cpp"
#include "friendfunction.cpp"
using namespace std;

int main()
{
    ifstream inp_user("userbase.txt");
    ifstream inp_sach("sachbase.txt");

    DSLK<Node<Sach>> sachlist;
    DSLK<Node<User>> userlist;
    read_file(inp_user, userlist);
    read_file(inp_sach, sachlist);

    if (borrowbook(find_id("00004", userlist), find_id("000005", sachlist)))
        cout << "borrow_success\n";
    else
        cout << "borrow_failed\n";

    if (returnbook(find_id("00004", userlist), find_id("000005", sachlist)))
        cout << "return_success\n";
    else
        cout << "return_failed\n";

    inp_user.close();
    inp_sach.close();

    ofstream out_user("userbase.txt");
    ofstream out_sach("sachbase.txt");
    write_file(out_sach, sachlist);
    write_file(out_user, userlist);
    cout << "writefile success\n";
    return 1;
}