#ifndef TEMPLATE_H
#define TEMPLATE_H

//exception marks
#define MEMBER_NOTFOUND (int)1


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
    template <class U>
    bool insert(U &);//insert a member to the bottom
    template <class U>
    bool remove(U &);//find and remove a member
    template <class U> 
    T& update(U &);//update a member
    template <class U>
    T *find(U &);
    void display();//display the list
    
    template<class T>
    friend void write_file<>(ofstream &, DSLK<T>&);

    template<class T>
    friend T& find_id(const string &, DSLK<Node<T>>&);
};

#endif