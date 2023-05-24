#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

int	Fixed::toInt( void ) const
{
	return (roundf((float)this->numberValue / (1 << Fixed::fractionalBits)));
}

float Fixed::toFloat( void ) const
{
	return ((float)this->numberValue / (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called\n";
	this->numberValue = (int)roundf(number * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const float fnumber)
{
	std::cout << "Float constructor called\n";
	this->numberValue = (int)roundf(fnumber * (1 << Fixed::fractionalBits));
}

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
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
		this->numberValue = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed &other)
{
	os << other.toFloat();
	return os;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}
