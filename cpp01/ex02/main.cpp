#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "string address:\t\t" << &str << std::endl
			  << "stringPTR address:\t" << stringPTR << std::endl
			  << "stringREF address:\t" << &stringREF << std::endl
			  << "string value:\t\t" << str << std::endl
			  << "stringPTR value:\t" << *stringPTR << std::endl
			  << "stringREF value:\t" << stringREF << std::endl;
	return 0;
}