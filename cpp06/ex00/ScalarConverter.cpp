#include "ScalarConverter.hpp"
# include <cctype>
# include <cstdlib>
# include <bits/stdc++.h>
# include <cstring>

const char *ScalarConverter::InvalidInput::what() const throw() {
	return "Invalid input";
};

const char *ScalarConverter::NanInput::what() const throw() {
	return "Input is NaN";
};

void ScalarConverter::convert( std::string inputValue ) {
	
	const char *cString = inputValue.c_str();

	char ch = static_cast<char>(std::atoi(cString));
	int in = static_cast<int>(std::atoi(cString));
	float fl = static_cast<float>(std::atof(cString));
	double doub = static_cast<double>(std::atof(cString));
	try {
		//check input
		if (inputValue == "nan" or inputValue == "nanf")
			throw NanInput();
		if (inputValue != "inf" && inputValue != "inff"
			&& inputValue != "-inf" && inputValue != "-inff")
		{
			if ((inputValue[0] == '-' and isdigit(inputValue[1]) == false)
				or (inputValue[0] != '-' and isdigit(inputValue[0]) == false))
				throw InvalidInput();
		}
		//print char
		{
			if (std::isinf(fl))
				std::cout << "char: " << "impossible\n";
			else
				(ch >= 32 and ch <= 126)
					? std::cout << "char: " << ch << "\n"
					: std::cout << "char: " << "Non displayable\n";
		}
		//print int
		{
			(std::isinf(fl))
				? std::cout << "int: " << "impossible\n"
				: std::cout << "int: " << in << "\n";
		}
		//print float
		{
			if ( std::isinf(fl) )
				( fl < 0 )
					? std::cout << "float: " << "-inff\n"
					: std::cout << "float: " << "inff\n";
			else
				( fl == in )
					? std::cout << "float: " << fl << ".0f\n"
					: std::cout << "float: " << fl << "f\n";
		}
		//print double
		{
			if ( std::isinf(doub) )
				( doub < 0 )
					? std::cout << "double: " << "-inf\n"
					: std::cout << "double: " << "inf\n";
			else
				( doub == in )
					? std::cout << "double: " << doub << ".0\n"
					: std::cout << "double: " << doub << "\n";
		}
	} catch(const std::exception& e) {
		if(std::strcmp(e.what(), "Invalid input") == 0)
			std::cout << e.what() << "\n";
		else {
			std::cout << "char: " << "impossible" << "\n";
			std::cout << "int: " << "impossible" << "\n";
			std::cout << "float: " << "nanf" << "\n";
			std::cout << "double: " << "nan" << "\n";
		}
	}
};

ScalarConverter::ScalarConverter() {};

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this == &other) {}
	return (*this);
}