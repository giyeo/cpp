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
	this->numberValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
		this->numberValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}