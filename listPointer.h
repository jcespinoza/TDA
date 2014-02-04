/* 
 * File:   listPointer.h
 * Author: jaycespinoza
 *
 * Created on January 29, 2014, 12:51 AM
 */

#ifndef LISTPOINTER_H
#define	LISTPOINTER_H
class Node{
public:
    int value;
    Node* next;
};

class ListP{
public:
    ListP(int);
    ListP();
    ~ListP();
    int insert(int,int);
    int first();
    int last();
    int next(int);
    int remove(int);
    int printList();
    void setSize(int);
    int get(int);
    int getCount(){return count;}
    int getSize(){return size;}
    Node * goTo(int);
    //int size(){return suzy;}
private:
    int size;
    int count;
    Node* firstN;
    Node* lastN;
};

#endif	/* LISTPOINTER_H */

