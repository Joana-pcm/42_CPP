#pragma once
#include <iostream>

class Fixed
{
	private:
	int                 _fixedPointValue;
	static const int    _fractionalBits = 8;
	public:
	Fixed();
	~Fixed();
	Fixed( const Fixed &src );
	Fixed &operator=( const Fixed &src );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};