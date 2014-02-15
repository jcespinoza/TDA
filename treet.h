#ifndef TREET_H
#define TREET_H
#include "nodetree.h"
#include "iostream"
using namespace std;

template <class T>
class TreeT
{
public:
    TreeT();

    void insert(T val);
    //void removeNode(NodeTree<T>* root, NodeTree<T>* target);
    void printValues();
    void printNodes(NodeTree<T>*);
    void insertNode(NodeTree<T>* &root, T val);
    NodeTree<T>* mainRoot;

};

#endif // TREET_H
