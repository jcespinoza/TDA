#ifndef NODETREE_H
#define NODETREE_H

template <class T>
class NodeTree{
public:
    NodeTree(T val = 0){
        value = val;
        leftChild = 0;
        rightChild = 0;
    }

    NodeTree<T>* leftChild;
    NodeTree<T>* rightChild;
    T value;
};

#endif // NODETREE_H
