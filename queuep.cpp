#include "queue.h"
#include "listPointer.h"
#include <iostream>

using namespace std;

QueueP::QueueP(int size){
    setSize(size);
}

QueueP::~QueueP(){
    
}

void QueueP::insert(int val) {
    ListP::insert(getCount(),val);
}

int QueueP::take(){
    int temp = first();
    remove(0);
    return temp;
}