#include "queue.h"
#include "listPointer.h"
#include <iostream>

using namespace std;

QueueP::QueueP(int size=10):ListP(size){
    setSize(size);
}

QueueP::~QueueP(){
    
}

int QueueP::insert(int val) {
    return ListP::insert(getCount(),val);
}

int QueueP::take(){
    int temp = first();
    remove(0);
    return temp;
}
