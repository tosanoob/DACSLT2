#ifndef TEMPLATE_H
#define TEMPLATE_H

//Double linked list template implementation

template <class U>
class Node
{
private:
    U data;
    Node *next;
    Node *prev;

    //---------------
public:
    Node(U&);
    Node(const U&);
    Node *tonext();
    Node *toprev();
    U &getdata();
    void setnext(Node *);
    void setprev(Node *);
    ~Node();
};

template <class T>
class DSLK
{
private:
    int size;
    T *head;
    T *tail;

public:
    // CRUD
    DSLK(); //constructor
    ~DSLK();//destructor
    bool insert(T &);//insert a member to the bottom
    bool remove(T &);//find and remove a member 
    bool update(T &);//update a member
    void display();//display the list
    T *find(T &);
};

#endif