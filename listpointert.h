#ifndef LISTPOINTERT_H
#define LISTPOINTERT_H

#include "nodet.h"
template <class T>
class ListPointerT
{
public:
    ListPointerT(int size = 10){
        this->size = size;
        count = 0;
        firstN = 0;
        lastN = 0;
    }

    ~ListPointerT(){
        while(count > 0)
            remove(0);
        lastN = 0;
        delete lastN;
    }
    int insert(int pos, T val){
        if(pos < 0 || pos > count || pos > getSize() || count == getSize())
            return -1;

            NodeT<T>* n = new NodeT<T>();
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
            NodeT<T>* cursor = firstN;
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

    T next(int pos){
        NodeT<T>* cursor = goTo(pos+1);
        return (cursor == 0)?-1:cursor->value;
    }

    int purge(){
        int p = 0;
        int q;
        while( p < count -1 ){
            q = p + 1;
            while(q <= count-1){
                if(get(p) == get(q)){
                    remove(q);
                }else{
                    q++;
                }
            }
            p++;
        }
        return 0;
    }

    int remove(int pos){
        if(pos < 0 || pos > count || pos > size)
            return -1;

        if(pos == 0){
            NodeT<T>* target = firstN;
            if(firstN != 0)
                firstN = firstN->next;
            count--;
            target->next = 0;
            delete target;
            return 0;

        }else if(pos == count-1){
            NodeT<T>* target = firstN;
            NodeT<T>* targPrev;

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
            NodeT<T>* target = firstN;
            NodeT<T>* targPrev = 0;

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

    int printList(){
        NodeT<T>* cursor = firstN;
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

    T get(int pos){
        if(pos < 0 || pos > count-1 || pos > size)
            return -1;
        NodeT<T>* cursor = firstN;
        for(int i = 0; i < pos; i++){
            cursor = cursor->next;
        }
        return cursor->value;
    }

    int getCount(){return count;}
    int getSize(){return size;}

    NodeT<T>* goTo(int pos){
        if(pos < 0 || pos > count-1 || pos > size)
            return 0;
        NodeT<T>* cursor = firstN;
        for(int i = 0; i < pos; i++){
            cursor = cursor->next;
        }
        return cursor;
    }

private:
    int size;
    int count;
    NodeT<T>* firstN;
    NodeT<T>* lastN;
};

#endif // LISTPOINTERT_H