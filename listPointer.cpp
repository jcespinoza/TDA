#include "listPointer.h"
#include "listArray.h"
#include <iostream>

using namespace std;

ListP::ListP(int size) {
    this->size = size;
    count = 0;
    firstN = 0;
    lastN = 0;
}

ListP::ListP() {
    size = 10;
    count = 0;
    firstN = 0;
    lastN = 0;
}

void ListP::setSize(int i){
    if(i > 0)
        size = i;
    firstN = 0;
    lastN = 0;
}

ListP::~ListP(){
    while(count > 0)
        remove(0);
    lastN = 0;
    delete lastN;
}

int ListP::first(){
    if(firstN != NULL)
        return firstN->value;
    return -1;
}

int ListP::insert(int pos, int val){
    if(pos < 0 || pos > count || pos > size)
        return -1;
    
        Node* n = new Node();
        n->value = val;
        
    if(pos == 0){
        n->next = firstN;
        firstN = n;
        if(count == pos)
            lastN = firstN;
        count++;
        return 0;
        
    }else if(pos == count){
        n->next = 0;
        lastN->next = n;
        lastN = n;
        count++;
        return 0;
        
    }else{
        Node* cursor = firstN;
        for(int i = 0; i < pos; i++){
            cursor = cursor->next;
            if(cursor == 0){
                return -1;
            }
        }
        n->next = cursor->next;;
        cursor->next = n;
        count++;
        return 0;
    }
}

/*
int ListP::insert(int pos, int val){
    if(pos < 0 || pos > count){
        return -1;}
    if(pos == 0){
        Node* n = new Node();
        n->value = val;
        n->next = 0;
        if(firstN != 0)
            n->next = firstN->next;
        firstN = n;
        if(count == pos)
            lastN = n;
        count++;
        return 0;
    }
    Node* cursor = firstN;
    Node* cursorN = (firstN != 0)? firstN->next : 0;
    for(int i = 0; i <= pos; i++){
        if(cursor != 0){
            if(i == pos){
                Node* nuevo = new Node();
                nuevo->value = val;
                nuevo->next = cursor->next;
                cursor->next = nuevo;
                count++;
                return 0;
            }
        }else
            return -1;
        cursor = cursorN;
        cursorN = cursor->next;
    }
    return 0;
}
*/

int ListP::printList(){
    Node* cursor = firstN;
    int i = 0;
    while(cursor != 0){
        cout << "\nelement[" << i++ << "]:" << cursor->value;
        cursor = cursor->next;
    }
    return 0;
}

int ListP::last(){
    if(lastN != 0)
        return lastN->value;
    return -1;
}

int ListP::next(int pos){
    Node* cursor = goTo(pos+1);
    return (cursor == 0)?-1:cursor->value;
}

int ListP::remove(int pos){
    if(pos < 0 || pos > count || pos > size)
        return -1;
    
    if(pos == 0){
        Node* target = firstN;
        if(firstN != 0)
            firstN = firstN->next;
        count--;
        target->next = 0;
        delete target;
        return 0;
        
    }else if(pos == count-1){
        Node* target = firstN;
        Node* targPrev;
        
        while(target-> next != 0){
            targPrev = target;
            target = target->next;
        }
        lastN = targPrev;
        targPrev->next = 0;
        delete target;
        count--;
        return 0;
    }else{
        Node* target = firstN;
        Node* targPrev;
        
        for(int i = 0; i < pos; i++){
            targPrev = target;
            target = target->next;
        }
        targPrev->next = target->next;
        delete target;
        count--;
        return 0;
    }
}

int ListP::get(int pos){
    if(pos < 0 || pos > count-1 || pos > size)
        return -1;
    Node* cursor = firstN;
    for(int i = 0; i < pos; i++){
        cursor = cursor->next;
    }
    return cursor->value;
}

Node* ListP::goTo(int pos){
    if(pos < 0 || pos > count-1 || pos > size)
        return 0;
    Node* cursor = firstN;
    for(int i = 0; i < pos; i++){
        cursor = cursor->next;
    }
    return cursor;
}
