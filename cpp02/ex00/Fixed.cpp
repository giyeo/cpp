#include "Fixed.hpp"

const int FixedPointNumber::fractionalBits = 0;

int FixedPointNumber::getRawBits(void) const
{
	return (this->numberValue);
}

void FixedPointNumber::setRawBits(int const raw)
{
	this->numberValue = raw;
}

FixedPointNumber::FixedPointNumber(void)
{
	this->setRawBits(0);
}

FixedPointNumber::FixedPointNumber(const FixedPointNumber &other)
{
	numberValue = other.numberValue;
}
