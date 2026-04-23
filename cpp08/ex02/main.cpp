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

	std::cout << "After pop...\n" << mstack;
	std::cout << "Pushing more elements..." << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << mstack;
	std::cout << "\tTop element: " << mstack.top() << std::endl;

	std::stack<int> s(mstack);
	std::cout << "Testing copy constructor...\n[";
	for (s.size(); !s.empty(); s.pop())
		std::cout << s.top() << (s.size() == 1 ? "]\n" : ", " );

	std::cout << RED << "\nTesting the same code as a list\n" << RESET <<  std::endl;
	
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << mlist;
	std::cout << "\tTop element: " << mlist.back() << std::endl;

	mlist.pop_back();

	std::cout << "After pop...\n" << mlist ;
	std::cout << "Pushing more elements..."<< std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::cout << mlist;
	std::cout << "\tTop element: " << mlist.back() << std::endl;

	std::stack<int, std::list<int> > l(mlist);
	std::cout << "Testing copy constructor...\n[";
	for (l.size(); !l.empty(); l.pop())
		std::cout << l.top() << (l.size() == 1 ? "]\n" : ", " );

	MutantStack<std::string> mstack_string;
	std::cout << RED << "\nCreating mstack as stack of strings\n" << RESET << std::endl;
	mstack_string.push("Five");
	mstack_string.push("Seventeen");
	std::cout << mstack_string;
	mstack_string.pop();
	std::cout << "After pop...\n"<< mstack_string;
	std::cout <<"Adding more strings..."<< std::endl;
 	mstack_string.push("Three");
	mstack_string.push("Seven hundred thirty-seven");
	std::cout << mstack_string;
	return 0;
}