#include "easyfind.hpp"

#define RED "\033[31m"

int main()
{
	std::vector<int> vec(5);
	for (int i = 0; i < 5; ++i)
		vec[i] = i;

	try
	{
		std::cout << "Finding 3 in vector: " << *easyfind(vec, 3) << std::endl;
		std::cout << "Finding 4 in vector: " << *easyfind(vec, 4) << std::endl;
		std::cout << "Finding 0 in vector: " << *easyfind(vec, 0) << std::endl;
		std::cout << "Finding 6 in vector: " << *easyfind(vec, 6) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl;
	}

	return 0;
}