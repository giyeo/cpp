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

		int	getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		static const int fractionalBits;
		int numberValue;
};

#endif