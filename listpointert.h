#ifndef LISTPOINTERT_H
#define LISTPOINTERT_H

#include "nodet.h"
#include <iostream>
#include <QDebug>
#include <algorithm>
#include <ctime>

using namespace std;

template <class T>
class ListPointerT
{
public:
    int count;
    NodeT<T>* firstN;
    NodeT<T>* lastN;

    ListPointerT(){
        count = 0;
        firstN = 0;
        lastN = 0;
    }

    ~ListPointerT(){
        //code to release memory here
    }

    void insert(T val){
        //if(!isValid(val))
          //  return;
        NodeT<T>* newone = new NodeT<T>();
        newone->value = val;
        newone->next = 0;
        if(firstN == 0){
            firstN = newone;
            count++;
        }else{
            NodeT<T>* cursor = firstN;
            while(cursor->next != 0){
                cursor = cursor->next;
            }
            cursor->next = newone;
            count++;
        }
    }

    void release(){
        while(count > 0)
            remove(0);
    }

    void updateCount(){
        int c = 0;
        NodeT<T>* cursor = firstN;
        while(cursor != 0){
            cursor = cursor->next;
            c++;
        }
        count = c;
    }

    void insert(int pos, T val){
        //if(!isValid(val))
          //  return;

        NodeT<T>* newone = new NodeT<T>();
        newone->value = val;
        newone->next = 0;
        if(pos == 0){
            if(firstN == 0){
                firstN = newone;
            }else{
                newone->next = firstN;
                firstN = newone;
            }
            count++;
        }else{
            NodeT<T>* cursor = goTo(pos-1);
            if(cursor != 0){
                newone->next = cursor->next;
                cursor->next = newone;
                count++;
            }
        }
    }

    void remove(int pos){
        if(pos < 0 || pos >= count || firstN == 0)
            return;
        NodeT<T>* target = 0;
        if(pos == 0 ){
            target = firstN;
            firstN = firstN->next;
        }else{
            NodeT<T>* previo = goTo(pos-1);
            target = goTo(pos);
            previo->next = target->next;
        }
        delete target;
        count--;
    }

    NodeT<T>* disconnect(int pos){
        if(pos < 0 || pos >= count || firstN == 0)
            return 0;
        NodeT<T>* target = 0;
        if(pos == 0 ){
            target = firstN;
            firstN = firstN->next;
        }else{
            NodeT<T>* previo = goTo(pos-1);
            target = goTo(pos);
            previo->next = target->next;
        }
        count--;
        return target;
    }

    NodeT<T>* disconnectFrom(int pos){
        if(pos < 0 || pos >= count || firstN == 0)
            return 0;
        NodeT<T>* target = 0;
        if(pos == 0){
            target = firstN;
            firstN = 0;
            count = 0;
            lastN = 0;
        }else{
            target = goTo(pos);
            NodeT<T>* prev = goTo(pos-1);
            if(prev != 0)
                prev->next = 0;
        }
        updateCount();
        return target;
    }

    NodeT<T>* disconnectLast(){
        return disconnectFrom(count-1);
    }

    void append(NodeT<T>* node){
        if(firstN == 0)
            firstN = node;
        else{
            last()->next = node;
        }
        updateCount();
    }

    void purge(){
        int p = 0;
        int q;
        while( p < count-1 ){
            q = p + 1;
            while(q <= count-1){
                if(get(p) == get(q))
                    remove(q);
                else
                    q++;
            }
            p++;
        }
    }

    int removeDuplicates(T val){
        int p = getIndex(val);
        int q  = p + 1;
        if(p == -1)
            return -1;

        while(q <= count -1){
            if(get(q) == val)
                remove(q);
            else
                q++;
        }
        return 0;
    }

    int getCount(){
        return count;
    }

    NodeT<T>* first(){
        return firstN;
    }

    NodeT<T>* last(){
        if(firstN == 0)
            return 0;
        NodeT<T>* cursor = firstN;
        while(cursor->next != 0){
            cursor = cursor->next;
        }
        return lastN = cursor;
    }

    void printList(){
        NodeT<T>* cursor = firstN;
        int c = 0;
        while(cursor != 0){
            cout << "\nElement " << c << ": " << cursor->value;
            cursor = cursor->next;
            c++;
        }
    }

    NodeT<T>* goTo(int pos){
        if(pos < 0 || pos >= count)
            return 0;
        NodeT<T>* cursor = firstN;
        int c = 0;
        while(cursor != 0){
            if(c == pos)
                return cursor;
            cursor = cursor->next;
            c++;
        }
        return 0;
    }

    T get(int pos){
        NodeT<T>* cursor = goTo(pos);
        if(cursor == 0)
            return T();
        return cursor->value;
    }


    int getIndex(T val){
        int i = 0;
        NodeT<T>* cursor = firstN;
        while(cursor != 0){
            if(cursor->value == val)
                return i;
            i++;
            cursor = cursor->next;
        }
        return -1;
    }

    NodeT<T>* getPointer(T val){
        NodeT<T>* cursor = firstN;
        while(cursor != 0){
            if(cursor->value == val)
                break;
            cursor = cursor->next;
        }
        return cursor;
    }

    bool isEmpty(){
        return getCount() == 0 || firstN == 0;
    }

    T getLast(){
        if(last() == 0)
            return T();
        return lastN->value;
    }

    T getFirst(){
        if(firstN == 0)
            return T();
        return firstN->value;
    }

    void swap(int i, int j){
        if( i < 0 || j < 0 || i >= count || j >= count)
            return;

        if(i == j)
            return;

        T first =  get(i);
        T second = get(j);
        goTo(i)->value = second;
        goTo(j)->value = first;
    }

    void shuffleItems(){
        int currentR = 0;
        int x = 0;
        int y = getCount()-1;
        for(int i = 0; i < getCount(); i++){
            currentR = rand()%getCount();
            if(currentR%2 == 0){
                x = currentR;
                y = (x + 1);
            }
            swap(x,y);
            x = i;
            y = x + 1;
        }
    }
};

#endif // LISTPOINTERT_H
