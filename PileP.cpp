#include "PileP.h"
using namespace std;

PileP::PileP(int size){
    setSize(size);
}

void PileP::insert(int value){
    ListP::insert(getCount(), value);
}

int PileP::take(){
    int temp = get(getCount()-1);
    remove(getCount()-1);
    return temp;
}

PileP::~PileP(){}