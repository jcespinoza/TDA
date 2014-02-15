#include "treet.h"

template <class T>
TreeT<T>::TreeT()
{
    mainRoot = 0;
}

template <class T>
void TreeT<T>::insertNode(NodeTree<T>* &root, T val)
{
    if(root == 0){
        root = new NodeTree<T>();
        root->lSon = 0;
        root->rSon = 0;
        root->value = val;
    }else if(val < root->value){
        insertNode(root->lSon, val);
    }else{
        insertNode(root->rSon, val);
    }
}

template <class T>
void TreeT<T>::insert(T val)
{
    insertNode(mainRoot, val);
}

template <class T>
void TreeT<T>::printNodes(NodeTree<T>* root)
{
    if(root != 0){
        cout << "\nValue: " << root->value;
        printNodes(root->lSon);
        printNodes(root->rSon);
    }
}

template <class T>
void TreeT<T>::printValues()
{
    cout << "\n\nTREE:";
    printNodes(mainRoot);
}
