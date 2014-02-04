/* 
 * File:   PileP.h
 * Author: Jay C Espinoza
 *
 * Created on February 3, 2014, 1:11 PM
 */
#include "listPointer.h"
#include <iostream>

#ifndef PILEP_H
#define	PILEP_H
class PileP: public ListP{
public:
    PileP(int);
    ~PileP();
    void insert(int);
    int take();
private:
    
};


#endif	/* PILEP_H */

