#ifndef NODET2_H
#define NODET2_H
template <class T>
class NodeT2
{
public:
    T value;
    NodeT2<T>* next;
    NodeT2<T>* previous;
};

#endif // NODET2_H
