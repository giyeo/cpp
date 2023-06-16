#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
        std::cout << "Number of inputs are invalid, Example './convert 42' " << "\n";
        return 1;
    }
	ScalarConverter::convert(argv[1]);
}