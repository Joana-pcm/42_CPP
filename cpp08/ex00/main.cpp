#include "easyfind.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"
#define BROWN "\033[33m"

int main()
{
	std::cout << BROWN << "Test vector container\n"<< RESET;
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	try
	{
		std::cout << *easyfind(v, 5) << std::endl;
		std::cout << *easyfind(v, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}


	std::cout << BROWN << "Test list container\n"<< RESET;
	std::list<int> l;

	for (int i = 0; i < 20; i++)
	{
		l.push_back(i);
	}
	try
	{
		std::cout << *easyfind(l, 0) << std::endl;
		std::cout << *easyfind(l, 1000) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}


	std::cout << BROWN << "Test deque container\n"<< RESET;
	std::deque<int> d;

	for (int i = 0; i < 350; i++)
	{
		d.push_back(i);
	}

	try
	{
		std::cout << *easyfind(d, 349) << std::endl;
		std::cout << *easyfind(d, 560) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	return (0);
}