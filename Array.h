
#ifndef ARRAY_H
#define ARRAY_H


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T = string>

class Array {

public:
    //constructor
    Array();

    //destructor
    ~Array();

    //other
    int getSize() const;
    bool isFull() const;

    Array<T>& operator+=(T); // add to back of array
    Array<T>& operator-=(T); //remove elt from array
    T& operator[](int);      //return elt at index - err if OOB & exit(1)
    T& operator[](int) const;


private:
    int numElements;
    T* elements;

};

template <class T>
Array<T>::Array(){
    elements = new T[MAX_ARR];
    numElements = 0;
}

template <class T>
Array<T>::~Array(){
    delete [] elements;
}

template <class T>
Array<T>& Array<T>::operator+=(T t){
    if (numElements >= MAX_ARR) {
        cerr << "Array is full" << endl;
        return *this;
    }
    elements[numElements++] = t;
    return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(T t){
    int index = 0;
    while (index < numElements){
        if (t == elements[index]){
            --numElements;
            break;
        }
        ++index;
    }

    while (index < numElements){
        elements[index] = elements[index + 1];
        ++index;
    }
    return *this;
}

template <class T>
T& Array<T>::operator[](int index){
    if (index < 0 || index >= numElements) {
        cerr<<"index OOB"<<endl;
        exit(1);
    }
    return elements[index];
}

template <class T>
T& Array<T>::operator[](int index) const{
    if (index < 0 || index >= numElements) {
        cerr<<"index OOB"<<endl;
        exit(1);
    }
    return elements[index];
}

template <class T>
int Array<T>::getSize() const{
    return numElements;
}

template <class T>
bool Array<T>::isFull() const {
    return numElements >= MAX_ARR;
}


#endif //ARRAY_H
