#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printIt(T a) {
    std::cout << a << "\n";
}

template <typename T, typename Func>
void iter(T *address, int size, Func function) {
    for( int i = 0; i < size; i++) {
        function(address[i]);
    }
}

#endif