#include "Serializer.hpp"
#include <iostream>

int main( void ) {
	Data data;

	data.value = 42;
    std::cout << "Init Data" << "\n";
	std::cout << "Memory Adress: " << &data << "\n";
	std::cout << "Data value: " << data.value << "\n";
    std::cout << "\n";

    std::cout << "Serialize Data" << "\n";
	uintptr_t	raw = Serializer::serialize(&data);
	std::cout << "Serialize value: " << raw << "\n";
    std::cout << "In hexadecimal: 0x" << std::hex << raw << "\n";
    std::cout << std::dec << "\n";

    std::cout << "Deserialize Data" << "\n";
	Data *two = Serializer::deserialize(raw);
	std::cout << "Memory Adress: " << two << "\n";
	std::cout << "Data value: " << two->value << "\n";
    std::cout << "\n";
	
	return (0);
}