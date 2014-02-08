#include "listpointert.h"

template <class T>
ListPointerT<T>::ListPointerT(int size = 10)
{
    this->size = size;
    count = 0;
    firstN = 0;
    lastN = 0;
}

template <class T>
ListPointerT<T>::~ListPointerT()
{
}

template <class T>
int ListPointerT<T>::insert(int pos, T val)
{
    return 0;
}

template <class T>
T ListPointerT<T>::first()
{
}

template <class T>
T ListPointerT<T>::last()
{
}

template <class T>
T ListPointerT<T>::next(int)
{
}

template <class T>
int ListPointerT<T>::remove(int)
{
}

template <class T>
int ListPointerT<T>::printList()
{
}

template <class T>
void ListPointerT<T>::setSize(int)
{
}

template <class T>
T ListPointerT<T>::get(int)
{
}

template <class T>
NodeT<T> *ListPointerT<T>::goTo(int)
{
}

