/* 
 * File:   listArray.h
 * Author: jaycespinoza
 *
 * Created on January 28, 2014, 11:50 PM
 */

#ifndef LISTARRAY_H
#define	LISTARRAY_H
class ListAr{
public:
    ListAr(int);
    ~ListAr();
    int insert(int,int);
    int first();
    int last();
    int next(int);
    int purge();
    int remove(int);
    int printList();
    int getCount(){return count;}
    int getSize(){return size;}
    int get(int);
    //int size(){return suzy;}
private:
    int size;
    int count;
    int* elements;
};


#endif	/* LISTARRAY_H */

