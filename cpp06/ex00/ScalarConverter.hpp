#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	public:
		static void convert( std::string inputValue );

	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);

		class InvalidInput : public std::exception {
			const char *what() const throw();
		};
		class NanInput : public std::exception {
			const char *what() const throw();
		};
};

#endif