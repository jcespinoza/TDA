/* 
 * File:   queue.h
 * Author: Jay C Espinoza
 *
 * Created on February 3, 2014, 2:27 PM
 */
#include "listpointert.h"

#ifndef QUEUE_H
#define	QUEUE_H
template <class T>
class QueueP: public ListPointerT<T>{
public:
    QueueP(int size):ListPointerT<T>(size){}
    int insert(T val){
        return ListPointerT<T>::insert(ListPointerT<T>::getCount(),val);
    }
    int take(){
        T temp = this->first();
        this->remove(0);
        return temp;
    }

    ~QueueP(){}
private:
    
};


#endif	/* QUEUE_H */

