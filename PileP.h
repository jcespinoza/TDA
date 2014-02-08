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

    int reverse(int iter = 0){
        if(this->getCount() == 2){
            this->swap(0,1);
            return 0;
        }

        if( iter > this->getCount()/2)
            return 0;

        this->swap(0+iter, this->getCount()-1-iter);
        return reverse(iter+1);
    }

private:
    
};


#endif	/* PILEP_H */

