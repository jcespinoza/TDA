/* 
 * File:   main.cpp
 * Author: jaycespinoza
 *
 * Created on January 28, 2014, 11:48 PM
 */

#include <iostream>
#include "listArray.h"
#include "PileP.h"
#include "queue.h"
#include "listpointert.h"

using namespace std;

void test1(){
    cout << "TEST 1";
    ListP lista(5);
    cout << "\ninsert " << lista.insert(0,5);
    cout << "\ninsert " << lista.insert(1, 87);
    cout << "\ninsert " << lista.insert(2, 54);
    cout << "\ninsert " << lista.insert(0, 38);
    cout << "\ninsert " << lista.insert(1, 15);

    cout << "\nprim: " << lista.first();
    cout << "\nfin: " << lista.last();
    cout << "\nrec: " << lista.get(2);

    lista.printList();
    cout << "\nelim: " << lista.remove(2);
    cout << "\nprim: " << lista.first();
    cout << "\nfin: " << lista.last();

    cout << "\n\nNext: " << lista.next(2);
    cout << "\n";
    lista.printList();
    cout << "\n\n\n";
    lista = 0;

    PileP<int> p(10);
    p.insert(5);
    p.printList();
    p.insert(85);
    p.printList();
    p.take();
    p.printList();

    cout << "\n\n";
    QueueP q(10);
    q.insert(5);
    q.printList();
    q.insert(85);
    q.printList();
    q.take();
    q.printList();
}

void test2(){
    cout << "\n\nTEST2";
    ListPointerT<int> lista(5);
    cout << "\ninsert " << lista.insert(0,5);
    cout << "\ninsert " << lista.insert(1, 87);
    cout << "\ninsert " << lista.insert(2, 54);
    cout << "\ninsert " << lista.insert(0, 38);
    cout << "\ninsert " << lista.insert(1, 15);

    cout << "\nprim: " << lista.first();
    cout << "\nfin: " << lista.last();
    cout << "\nrec: " << lista.get(2);

    lista.printList();
    cout << "\nelim: " << lista.remove(2);
    cout << "\nprim: " << lista.first();
    cout << "\nfin: " << lista.last();

    cout << "\n\nNext: " << lista.next(2);
    cout << "\n";
    lista.printList();
    cout << "\n\n\n";
    lista = 0;
}

int main() {
    cout << "Compiled correctly :D\n";
    test1();
    test2();
    return 0;
}
