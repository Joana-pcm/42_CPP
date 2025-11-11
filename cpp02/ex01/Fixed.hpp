#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	private:
	int                 _fixedPointValue;
	static const int    _fractionalBits = 8;
	public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &src);
	Fixed(const int i);
	Fixed(const float f);
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed &operator=(const Fixed &src);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);
