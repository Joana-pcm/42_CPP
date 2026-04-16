#include "Span.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"
#define BROWN "\033[33m"

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

	std::cout << BROWN << "\nSearching..." << RESET << std::endl;
	std::cout << "Shortest Span:\t" << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span:\t" << sp.longestSpan() << std::endl;

	std::cout << BROWN << "\nTesting addNumber on full Span" << RESET << std::endl;
	try
	{
		sp.addNumber(20);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << BROWN << "\nTesting with insufficient numbers" << RESET << std::endl ;
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

		std::cout << "\033[33m" << "Test vector range\n"<< "\033[0m";
	Span sp2 = Span(100);
	std::vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		
		int random_int = rand() % 1000000;
		v.push_back(random_int);
	}
	try
	{
		sp2.addNumber(v.begin(), v.end());
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\033[33m" << "Test vector large range\n"<< "\033[0m";
	Span sp3 = Span(100000);
	std::vector<int> v2;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		
		int random_int = rand() % 1000000000;
		v2.push_back(random_int);
	}
	try
	{
		sp3.addNumber(v2.begin(), v2.end());
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}