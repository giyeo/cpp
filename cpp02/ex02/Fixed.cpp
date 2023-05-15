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
	this->setRawBits(0);
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
		this->setRawBits(other.getRawBits());
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


bool Fixed::operator>(const Fixed &n)
{
	return((this->toFloat() > n.toFloat()));
}

bool Fixed::operator>=(const Fixed &n)
{
	return((this->toFloat() >= n.toFloat()));
}

bool Fixed::operator<(const Fixed &n)
{
	return((this->toFloat() < n.toFloat()));
}

bool Fixed::operator<=(const Fixed &n)
{
	return((this->toFloat() <= n.toFloat()));
}

bool Fixed::operator==(const Fixed &n)
{
	return((this->toFloat() == n.toFloat()));
}

bool Fixed::operator!=(const Fixed &n)
{
	return((this->toFloat() != n.toFloat()));
}

float Fixed::operator+(const Fixed &other)
{
	return(this->toFloat() + other.toFloat());
}

float Fixed::operator-(const Fixed &other)
{
	return(this->toFloat() - other.toFloat());
}

float Fixed::operator*(const Fixed &other)
{
	return(this->toFloat() * other.toFloat());
}

float Fixed::operator/(const Fixed &other)
{
	return(this->toFloat() / other.toFloat());
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a.toFloat() < b.toFloat()) ? a : b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a.toFloat() > b.toFloat()) ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

Fixed& Fixed::operator++()
{
	++this->numberValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++this->numberValue;
	return temp;
}

Fixed& Fixed::operator--()
{
	--this->numberValue;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--this->numberValue;
	return temp;
}
