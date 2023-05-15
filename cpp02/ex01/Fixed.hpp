#ifndef __FIXED_HPP__
#define __FIXED_HPP__
#include <iostream>


class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed(void);
		Fixed(const int number);
		Fixed(const float fnumber);

		float toFloat( void ) const;
		int toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		static const int fractionalBits;
		int numberValue;
};

std::ostream& operator<<(std::ostream& os, const Fixed &other);
#endif