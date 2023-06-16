#include "ScalarConverter.hpp"
#include <limits>
#include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"

int main() {
	//Cool numbers
	std::cout << GREEN << "Cool normal Numbers\n" << RESET;
	ScalarConverter::convert("42");
	std::cout << "\n";
	ScalarConverter::convert("0");
	std::cout << "\n";
	ScalarConverter::convert("-42");
	std::cout << "\n";

	//float numbers
	std::cout << GREEN << "float Numbers\n" << RESET;
	ScalarConverter::convert("42.42");
	std::cout << "\n";
	ScalarConverter::convert("0.0");
	std::cout << "\n";
	ScalarConverter::convert("-42.12");
	std::cout << "\n";

	//Max int
	std::cout << GREEN << "Max int Numbers\n" << RESET;
	ScalarConverter::convert("-2147483648");
	std::cout << "\n";
	ScalarConverter::convert("2147483647");
	std::cout << "\n";

	//Overflow
	std::cout << GREEN << "Overflow int Numbers\n" << RESET;
	ScalarConverter::convert("-2147483649");
	std::cout << "\n";
	ScalarConverter::convert("2147483649");
	std::cout << "\n";

	//inf inff
	std::cout << GREEN << "inf Numbers Test\n" << RESET;

	float positiveInfinity = std::numeric_limits<float>::infinity();
	std::cout << YELLOW << "Value of positiveInfinity: " << positiveInfinity << RESET << "\n";
	ScalarConverter::convert("inf");

	std::cout << "\n";

	float negativeInfinity = -std::numeric_limits<float>::infinity();
	std::cout << YELLOW << "Value of negativeInfinity: " << negativeInfinity << RESET <<"\n";
	ScalarConverter::convert("-inf");

	std::cout << "\n";
	//nan
	std::cout << GREEN << "nan Test\n" << RESET;
	double doubleNaN = std::numeric_limits<double>::quiet_NaN();
	std::cout << YELLOW << "Value of doubleNaN: "<< doubleNaN << RESET << "\n";
	ScalarConverter::convert("nan");
}


