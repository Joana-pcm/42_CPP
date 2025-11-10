#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=( const Fixed &src )
{
	std::cout <<  "Copy Assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->setRawBits(src.getRawBits());
	return (*this);
}

Fixed::Fixed( const Fixed &src )
{
	this->_fixedPointValue = src._fixedPointValue;
	std::cout << "Copy constructor called" << std::endl;
}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}
void Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}