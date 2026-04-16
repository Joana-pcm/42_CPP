#include "Span.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

int main()
{
	srand(0);
	Span sp(5);
	sp.addNumber(std::rand() % 100);
	sp.addNumber(std::rand() % 100);
	sp.addNumber(std::rand() % 100);
	sp.addNumber(std::rand() % 100);
	sp.addNumber(std::rand() % 100);

	std::cout << "Span created and filled with random values.\n";
	std::cout << sp << std::endl;

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	std::cout << "\nTesting addNumber on full Span\n";
	try
	{
		sp.addNumber(20);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "\nTesting with insufficient numbers\n";
	try
	{
		Span sp2(5);
		sp2.addNumber(10);
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Span sp2(5);
		sp2.addNumber(10);
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}