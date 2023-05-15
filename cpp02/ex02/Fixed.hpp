#ifndef __FIXED_HPP__
#define __FIXED_HPP__
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed(void);
		Fixed(const int number);
		Fixed(const float fnumber);

		bool operator>(const Fixed &a);
		bool operator>=(const Fixed &a);
		bool operator<(const Fixed &a);
		bool operator<=(const Fixed &a);
		bool operator==(const Fixed &a);
		bool operator!=(const Fixed &a);

		float operator+(const Fixed &a);
		float operator-(const Fixed &a);
		float operator*(const Fixed &a);
		float operator/(const Fixed &a);

		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

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