#include "Base.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Base* obj = generate();
	std::cout << "Identifying by pointer: ";
	identify(obj);
	std::cout << "Identifying by reference: ";
	identify(*obj);

	delete obj;
	return 0;
}