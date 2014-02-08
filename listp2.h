#ifndef LISTP2_H
#define LISTP2_H
#include "nodet2.h"

template <class T>
class ListP2{
public:
    ListP2(int size = 10){
        this->size = size;
        count = 0;
        firstN = 0;
        lastN = 0;
    }

    ~ListP2(){
        while(count > 0)
            remove(0);
        lastN = 0;
        delete lastN;
    }

    int insert(int pos,T val){
        if(pos < 0 || pos > count || pos > size || count == getSize())
            return -1;

            NodeT2<T>* n = new NodeT2<T>();
            n->value = val;

        if(pos == 0){
            n->prev = 0;
            n->next = firstN;
            firstN = n;
            if(count == pos)
                lastN = firstN;
            count++;
            return 0;

        }else if(pos == count){
            n->next = 0;
            lastN->next = n;
            n->prev = lastN;
            lastN = n;
            count++;
            return 0;

        }else{
            NodeT2<T>* cursor = firstN;
            for(int i = 0; i < pos; i++){
                cursor = cursor->next;
                if(cursor == 0){
                    return -1;
                }
            }
            cursor->prev->next = n;
            n->prev = cursor->prev;
            n->next = cursor;
            cursor->prev = n;
            count++;
            return 0;
        }
    }

    T first(){
        if(firstN != NULL)
            return firstN->value;
        return -1;
    }

    T last(){
        if(lastN != 0)
            return lastN->value;
        return -1;
    }

    T next(int){
        NodeT2<T>* cursor = goTo(pos+1);
        return (cursor == 0)?-1:cursor->value;
    }

    int remove(int){
        if(pos < 0 || pos > count || pos > size)
            return -1;

        if(pos == 0){
            NodeT2<T>* target = firstN;
            if(firstN != 0)
                firstN = firstN->next;
            count--;
            target->next = 0;
            delete target;
            return 0;

        }else if(pos == count-1){
            NodeT2<T>* target = firstN;

            while(target-> next != 0)
                target = target->next;

            target->prev->next = 0;
            lastN = target->prev;
            target->prev = 0;

            delete target;
            count--;
            return 0;

        }else{
            NodeT2<T>* target = firstN;

            for(int i = 0; i < pos; i++)
                target = target->next;

            target->prev->next = target->next;
            target->next->prev = target->prev;

            delete target;
            count--;
            return 0;
        }
    }

    int printList(){
        NodeT2<T>* cursor = firstN;
        int i = 0;
        while(cursor != 0){
            cout << "\nelement[" << i++ << "]:" << cursor->value;
            cursor = cursor->next;
        }
        return 0;
    }

    void setSize(int i){
        if(i > 0)
            size = i;
        firstN = 0;
        lastN = 0;
    }

    int get(int pos){
        if(pos < 0 || pos > count-1 || pos > size)
            return -1;
        NodeT2<T>* cursor = firstN;
        for(int i = 0; i < pos; i++){
            cursor = cursor->next;
        }
        return cursor->value;
    }

    int getCount(){return count;}

    int getSize(){return size;}

    NodeT2<T> * goTo(int pos){
        if(pos < 0 || pos > count-1 || pos > size)
            return 0;
        NodeT2<T>* cursor = firstN;
        for(int i = 0; i < pos; i++){
            cursor = cursor->next;
        }
        return cursor;
    }

private:
    int size;
    int count;
    NodeT2<T>* firstN;
    NodeT2<T>* lastN;
};
#endif // LISTP2_H
