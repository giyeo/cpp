#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->numberValue);
}

void Fixed::setRawBits(int const raw)
{
	this->numberValue = raw;
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	numberValue = other.numberValue;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{}
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}