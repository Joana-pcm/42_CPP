#include "Iter.hpp"

int main()
{
	const size_t intSize = 5;
	int intArray[intSize] = {1, 2, 3, 4, 5};
	std::cout << "Original int array:" << std::endl;
	iter(intArray, intSize, printElement);
	iter(intArray, intSize, incrementElement);
	std::cout << "Incremented int array:" << std::endl;
	iter(intArray, intSize, printElement);

	const size_t charSize = 3;
	std::string strArray[charSize] = {"hello", "world", "cpp"};
	std::cout << "\nOriginal string array:" << std::endl;
	iter(strArray, charSize, printElement);
	iter(strArray, charSize, toUpperElement);
	std::cout << "Uppercase string array:" << std::endl;
	iter(strArray, charSize, printElement);
	return 0;
}