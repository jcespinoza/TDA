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
    cout << "\nTEST 1 Pile and Queue";

    PileP<int> p(10);
    p.insert(5);
    p.printList();
    p.insert(85);
    p.printList();
    p.take();
    p.printList();

    cout << "\n\n";
    QueueP<int> q(10);
    q.insert(5);
    q.printList();
    q.insert(85);
    q.printList();
    q.take();
    q.printList();
}

void test2(){
    cout << "\n\nTEST2 Pointers";
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

void test3(){
    cout << "\n\nTEST3 Array";
    ListAr<int> lista(5);
    cout << "Created the list";
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
    cout << "Cleaning the list";
    lista = 0;
}

void test4swap(){
    cout << "\nSWAP TEST";
    ListPointerT<int> lista(10);
    lista.insert(0, 3);
    lista.insert(1, 6);
    lista.insert(2, 15);
    lista.insert(3, 5);
    lista.printList();
    lista.swap(1,0);
    lista.printList();
}

void test5reverse(){
    cout << "\nPILE REVERSE TEST";
    PileP<int> lista(10);
    lista.insert(1);
    lista.insert(2);
    lista.insert(3);
    lista.insert(4);
    lista.insert(3);
    lista.insert(6);
    lista.insert(7);

    lista.printList();
    lista.reverse();
    lista.printList();
    lista.removeDuplicates(3);
    lista.printList();
}

void exercise1(){
    cout << "\n\nEnter and expresion. NO spaces. One digit numbers only.\n";
    const int MAX_LENGTH = 8;

    PileP<char> expresionInfija(MAX_LENGTH);
    char* input = new char[MAX_LENGTH];

    cin.getline(input, MAX_LENGTH, '\n');
    cout << "Taken " << input << " as the input";
    char* cursor = input;

    while(*cursor != '\0'){
        expresionInfija.insert(*cursor);
        cursor++;
    }
    expresionInfija.printList();
    delete[] input;
}

int main(){
    //test1();
    //test2();
    //test3();
    //test4swap();
    //test5reverse();
    exercise1();

    return 0;
}
