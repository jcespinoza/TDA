#include "PileP.h"
using namespace std;

PileP::PileP(int size=10):ListP(size){
    setSize(size);
}

int PileP::insert(int value){
    return ListP::insert(getCount(), value);
}

int PileP::take(){
    int temp = get(getCount()-1);
    remove(getCount()-1);
    return temp;
}

PileP::~PileP(){}
