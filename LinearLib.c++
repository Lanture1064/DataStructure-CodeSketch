/*written in c++*/
#include <iostream>
using namespace std;

template<class T>
class Lnode
{
    friend class list<T>;
private:
    T value;
    Lnode* next;
public:
    Lnode();
    ~Lnode();
    Lnode(const T& item);
    
    Lnode<T>* CreateNode(T value,Lnode<T>* next); //
    Lnode<T>* NextNode(){return next;})            //
    void InsertAfter(Lnode<T>* p);                //
    Lnode<T>* RemoveAfter();                      //return point of the new NextNode
};

template <class T>
class list
{
public:
    Lnode<T>* head;
    Lnode<T>* first;
    Lnode<T>* last;

public:
    list(const T& value){last = first = new Lnode<T>(value)};
    ~list();
    void EmptyList();
    bool isEmpty()const;
    int Length()const;
    Lnode<T>* GetNode(int i);
    Lnode<T>* GetNode(T value);
    T GetValue(int i);
};

template<class T>
Lnode<T>::Lnode():next(nullptr){};

template<class T>
Lnode<T>::Lnode(const T& value):value(value),next(nullptr){};

template<class T>
Lnode<T>* Lnode<T>::CreateNode(T value,Lnode<T>* nextlink = nullptr)
{
    Lnode<T>* newnode = new Lnode<T>(value);
    newnode->next = nextlink;
    return newnode;
}

template<class T>
Lnode<T>* Lnode<T>::RemoveAfter()
{
    Lnode<T>* p = this->next;
    if(p == nullptr){cerr << "Hey I have no successor to remove bro!" << endl;return p;}
    this->next = p->next;
    delete p;
    return this->next;
}

template <class T>
void Lnode<T>::InsertAfter(Lnode<T>* p)
{
    p->next = next;
    next = p;
}

template<class T>
list<T>::~list()
{
    EmptyList();
    delete head;
}

template<class T>
void list<T>::EmptyList()
{
    Lnode<T>* p;
    while(head->next != nullptr)
    {
        p = head->next;
        head->next = p->next;
        delete p;
    }
    tail = head;
}

template<class T>
int list<T>::Length()const
{
    Lnode<T>* p = head->next;
    int count = 0
    while(p != nullptr)
    {
        p = p->next;
        count++;
    }
    return count;
}

template<class T>
Lnode<T>* list<T>::GetNode(T value)
{
    Lnode<T>* p;
    while(p != nullptr && p->value != value){p = p->next;}
    return p;
}

template<class T>
Lnode<T>* list<T>::GetNode(int i)
{
    Lnode<T>* p;
    int count = 0;
    while(p != nullptr && count !=i){p = p->next;i++;}
    return p;
}

T list<T>::GetValue(int i)
{
    Lnode<T>* p;
    int count = 0;
    while(p !=nullptr && count !=i)
    {
        p = p->next;
        i++;
    }
    return p->value;//result distinuguishment needed.
}

template<class T>
bool list<T>::isEmpty()
{
    if(this->head->next == nullptr && this->first == this->last == nullptr){return 1;}
    else {return 0;}
}
