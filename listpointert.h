#ifndef LISTPOINTERT_H
#define LISTPOINTERT_H

#include "nodet.h"
template <class T>
class ListPointerT
{
public:
    ListPointerT(int);
    ~ListPointerT();
    int insert(int,T);
    T first();
    T last();
    T next(int);
    int remove(int);
    int printList();
    void setSize(int);
    T get(int);
    int getCount(){return count;}
    int getSize(){return size;}
    NodeT<T>* goTo(int);
private:
    int size;
    int count;
    NodeT<T>* firstN;
    NodeT<T>* lastN;
};

#endif // LISTPOINTERT_H
