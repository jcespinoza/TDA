/* 
 * File:   listArray.h
 * Author: jaycespinoza
 *
 * Created on January 28, 2014, 11:50 PM
 */

#ifndef LISTARRAY_H
#define	LISTARRAY_H
#include <iostream>
using namespace std;

template <class T>
class ListAr{
private:
    int size;
    int count;
    int* elements;
public:
    ListAr(int size = 10){
        this->size = size;
        elements = new int[size];
        count = 0;
    }

    int insert(int pos, T value){
        if(pos < 0 || pos >= size || pos > count)
                return -1;

        if(count > size - 1)
            return -1;

        for(int i = count; i >= pos; i--){
            elements[i+1] = elements[i];
        }
        count++;
        elements[pos] = value;
        return 0;
    }

    int first(){
        if(count > 0)
            return elements[0];
        return -1;
    }

    int last(){
        if(count > 0)
            return elements[count-1];
        return -1;
    }

    int next(int pos){
        if(pos >= count - 1 || pos < 0)
            return -1;
        return elements[pos + 1];
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
        if( pos < 0 || pos >= count)
            return -1;
        for(int i = pos; i <= count - 1; i++)
            elements[i] = elements[i+1];
        count--;
        return 0;
    }

    int printList(){
        for(int i = 0; i < count; i++)
            cout << "\nelement[" << i << "]:" << elements[i];
        return 0;
    }

    int getCount(){return count;}

    int getSize(){return size;}

    int get(int pos){
        if(pos >= count || pos < 0)
            return -1;
        return elements[pos];
    }

    ~ListAr(){
        elements = nullptr;
        delete elements;
    }
};


#endif	/* LISTARRAY_H */

