#ifndef NODET_H
#define NODET_H

template <class T>
class NodeT
{
public:
    T value;
    NodeT<T>* next;
};

#endif // NODET_H
