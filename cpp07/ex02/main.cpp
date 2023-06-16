#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> one(25);
	Array<char> two(20);
	Array<float> three(18);
	Array<double> four(15);
	Array<int> five(10);
    Array<int> test;
    
    std::cout << test.size() << std::endl;

}