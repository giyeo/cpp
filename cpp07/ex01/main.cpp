#include "iter.hpp"

int main() {
    // Test 1: Printing elements of an integer array
    int intArr[] = {1, 2, 3, 4, 5};
    std::cout << "Printing elements of int array: \n";
    iter(intArr, 5, printIt<int>);
    std::cout << std::endl;

    // Test 2: Printing elements of a character array
    char charArr[] = {'H', 'e', 'l', 'l', 'o'};
    std::cout << "Printing elements of char array: \n";
    iter(charArr, 5, printIt<char>);
    std::cout << std::endl;

    // Test 3: Printing squares of elements of a floating-point array
    float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Printing squares of elements of float array: \n";
    iter(floatArr, 5, printIt<float>);
    std::cout << std::endl;

    return 0;
}