/* 
 * File:   queue.h
 * Author: Jay C Espinoza
 *
 * Created on February 3, 2014, 2:27 PM
 */
#include "listPointer.h"

#ifndef QUEUE_H
#define	QUEUE_H
class QueueP: public ListP{
public:
    QueueP(int);
    void insert(int);
    int take();
    ~QueueP();
private:
    
};


#endif	/* QUEUE_H */

