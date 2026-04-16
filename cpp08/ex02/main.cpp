#include "MutantStack.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack;
	std::cout << "\tTop element: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "\nAfter pop...\n" << mstack << std::endl;
	std::cout << "Pushing more elements...\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << mstack;
	std::cout << "\tTop element: " << mstack.top() << std::endl;

	std::stack<int> s(mstack);
	std::cout << "\nTesting copy constructor...\n[";
	for (s.size(); !s.empty(); s.pop())
		std::cout << s.top() << (s.size() == 1 ? "]\n" : ", " );
	return 0;
}