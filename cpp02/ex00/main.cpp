#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b;

	std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
	std::cout << "b.getRawBits(): " << b.getRawBits() << std::endl;

	a.setRawBits(42);
	b.setRawBits(84);

	std::cout << "After setting raw bits:" << std::endl;
	std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
	std::cout << "b.getRawBits(): " << b.getRawBits() << std::endl;

	return 0;
}