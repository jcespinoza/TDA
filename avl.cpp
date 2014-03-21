#include "avl.h"

template <class T>
void AVL<T>::insert(T nValue)
{
    insert(&rootNode, nValue);
}

template <class T>
void AVL<T>::printTree()
{
    cout << "Height: " << height(rootNode) << "\n";
    printNode(rootNode);
}

template <class T>
void AVL<T>::insert(NodeTree<T> **root, T nValue)
{
    if(*root == 0)
        *root = new NodeTree<T>(nValue);

    if(nValue < (*root)->value){
        insert(&((*root)->leftChild), nValue);
        if(height((*root)->leftChild) - height((*root)->rightChild) == 2){
            if(nValue < (*root)->leftChild->value)
                rotateLeftOnce(&(*root));
            else
                rotateLeftTwice(&(*root));
        }
    }else if(nValue > (*root)->value){
        insert(&((*root)->rightChild), nValue);
        if(height((*root)->rightChild) - height((*root)->leftChild) == 2){
            if(nValue > (*root)->rightChild->value)
                rotateRightOnce(&(*root));
            else
                rotateRightTwice(&(*root));
        }

    }
}

template <class T>
void AVL<T>::printNode(NodeTree<T> *root, int indent)
{
    if(root != 0){
        if(root->rightChild) printNode(root->rightChild, indent+4);
        if (indent) {
            for(int i = 0; i < indent; i++)
                cout << ' ';
        }
        cout << root->value << "\n ";
        if(root->leftChild) printNode(root->leftChild, indent+4);
    }
}

template <class T>
void AVL<T>::rotateLeftTwice(NodeTree<T> **root)
{
    rotateRightOnce(&((*root)->leftChild));
    rotateLeftOnce(&(*root));
}

template <class T>
void AVL<T>::rotateLeftOnce(NodeTree<T> **root)
{
    NodeTree<T>* other;

    other = (*root)->leftChild;
    (*root)->leftChild = other->rightChild;
    other->rightChild = (*root);
    (*root) = other;
}

template <class T>
void AVL<T>::rotateRightOnce(NodeTree<T> **root)
{
    NodeTree<T> *other;

    other = (*root)->rightChild;
    (*root)->rightChild = other->leftChild;
    other->leftChild = (*root);
    (*root) = other;
}

template <class T>
void AVL<T>::rotateRightTwice(NodeTree<T> **root)
{
    rotateLeftOnce(&((*root)->rightChild));
    rotateRightOnce(&(*root));
}

template <class T>
int AVL<T>::height(NodeTree<T> *root)
{
    int leftDepth;
    int rightDepth;
    if(root == 0)
        return 0;
    leftDepth = height(root->leftChild);
    rightDepth = height(root->rightChild);
    if(leftDepth > rightDepth)
        return leftDepth +1;
    else
        return rightDepth +1;
}
