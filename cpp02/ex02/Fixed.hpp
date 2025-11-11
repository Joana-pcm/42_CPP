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
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed &operator=(const Fixed &src);
	Fixed operator+(const Fixed &src) const;
	Fixed operator-(const Fixed &src) const;
	Fixed operator*(const Fixed &src) const;
	Fixed operator/(const Fixed &src) const;
	bool operator>(const Fixed &src) const;
	bool operator<(const Fixed &src) const;
	bool operator>=(const Fixed &src) const;
	bool operator<=(const Fixed &src) const;
	bool operator==(const Fixed &src) const;
	bool operator!=(const Fixed &src) const;
	Fixed &operator++();            // Prefix increment
	Fixed operator++(int);          // Postfix increment
	Fixed &operator--();            // Prefix decrement
	Fixed operator--(int);          // Postfix decrement
	static Fixed &min(Fixed &a, Fixed &b);
	static const  Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const  Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);
