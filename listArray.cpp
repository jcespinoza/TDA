#include "listArray.h"
#include <iostream>

using namespace std;

ListAr::ListAr(int size) {
    this->size = size;
    elements = new int[size];
    count = 0;
}

ListAr::~ListAr() {
    if(elements != 0){
        delete[] elements;
    }
}

int ListAr::insert(int pos, int value){
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

int ListAr::printList(){
    for(int i = 0; i < count; i++){
        cout << "\nelement[" << i << "]:" << elements[i];
    }
    return 0;
}

int ListAr::first(){
    if(count > 0)
        return elements[0];
    return -1;
}

int ListAr::last(){
    if(count > 0)
        return elements[count-1];
    return -1;
}

int ListAr::next(int pos){
    if(pos >= count - 1 || pos < 0)
        return -1;
    return elements[pos + 1];
}

int ListAr::purge(){
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

int ListAr::remove(int pos){
    if( pos < 0 || pos >= count)
        return -1;
    for(int i = pos; i <= count - 1; i++)
        elements[i] = elements[i+1];
    count--;
    return 0;
}

int ListAr::get(int pos){
    if(pos >= count || pos < 0)
        return -1;
    return elements[pos];
}
