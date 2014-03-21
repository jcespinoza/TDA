#ifndef AVL_H
#define AVL_H
#include "nodetree.h"
#include <iostream>
using namespace std;

template <class T>
class AVL
{
public:
    AVL(){
        rootNode = 0;
    }

    void insert(T nValue);
    void printTree();
protected:
    NodeTree<T>* rootNode;
private:
    void insert(NodeTree<T>** root, T nValue);
    void printNode(NodeTree<T>* root, int indent=0);
    void rotateLeftTwice(NodeTree<T>** root);
    void rotateLeftOnce(NodeTree<T>** root);
    void rotateRightOnce(NodeTree<T>** root);
    void rotateRightTwice(NodeTree<T>** root);
    int height(NodeTree<T>* root);

};

#endif // AVL_H
