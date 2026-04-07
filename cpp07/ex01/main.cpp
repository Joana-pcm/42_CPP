#include "Iter.hpp"

int main()
{
	const size_t intSize = 5;
	int intArray[intSize] = {1, 2, 3, 4, 5};
	std::cout << "Original int array:" << std::endl;
	iter(intArray, intSize, printElement<const int>);
	iter(intArray, intSize, incrementElement<int>);
	std::cout << "\nIncremented int array:" << std::endl;
	iter(intArray, intSize, printElement<const int>);

	const size_t charSize = 3;
	std::string strArray[charSize] = {"hello", "world", "cpp"};
	std::cout << "\nOriginal string array:" << std::endl;
	iter(strArray, charSize, printElement<const std::string>);
	iter(strArray, charSize, toUpperElement<std::string>);
	std::cout << "\nUppercase string array:" << std::endl;
	iter(strArray, charSize, printElement<const std::string>);
	return 0;
}