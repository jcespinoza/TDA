#ifndef NODETREE_H
#define NODETREE_H

template <class T>
class NodeTree{
public:
    NodeTree<T>* lSon;
    NodeTree<T>* rSon;
    T value;
};

#endif // NODETREE_H
