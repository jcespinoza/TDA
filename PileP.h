/* 
 * File:   PileP.h
 * Author: Jay C Espinoza
 *
 * Created on February 3, 2014, 1:11 PM
 */
#include "listpointert.h"
#include <iostream>

#ifndef PILEP_H
#define	PILEP_H
template <class T>
class PileP: public ListPointerT<T>{
public:
    PileP(int size=10):ListPointerT<T>(size){}
    ~PileP(){}
    int insert(T val){
        return ListPointerT<T>::insert(this->getCount(), val);
    }

    T take(){
        T temp = this->get(this->getCount()-1);
        this->remove(this->getCount()-1);
        return temp;
    }

private:
    
};


#endif	/* PILEP_H */

