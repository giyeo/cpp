#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class FixedPointNumber
{
	public:
		FixedPointNumber(void);
		FixedPointNumber(const FixedPointNumber &other);
		FixedPointNumber& operator=(const FixedPointNumber &other);
		~FixedPointNumber(void);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		static const int fractionalBits;
		int numberValue;
};

#endif