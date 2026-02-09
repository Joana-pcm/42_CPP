#include "Array.hpp"
template <typename T>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */

void manip_array(Array<T>& ar, T& val, size_t pos)
{
	try
	{
		ar[pos] = val;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

template<typename T>
void test_array(T a, T b, T c, T d)
{
	std::cout << YELLOW "\nINIT TEST\n" RESET;
	Array<T> arr1;
	Array<T> arr2(4);
	Array<T> arr3(arr2);
	std::cout << "let's check inside : arr1 (empty array)\n";
	std::cout << arr1;
	std::cout << "let's check inside : arr2 (size 4)\n";
	std::cout << arr2;
	std::cout << "let's check inside : arr3 (copy of arr2)\n";
	std::cout << arr3;

	std::cout << "let's modify the last 2\n";
	manip_array(arr2, a, 0);
    manip_array(arr3, a, 3);
    manip_array(arr3, b, 1);
    manip_array(arr3, c, 2);

	std::cout << "\nAfter manipulations:\n";
    std::cout << "arr2:\n"; std::cout << arr2;
    std::cout << "arr3:\n"; std::cout << arr3;

	std::cout << "\nlet's create an array 4 by copy assign of arr3\n";
	Array<T> arr4 = arr3;
	std::cout << "arr4:\n"; std::cout << arr4;
	
	std::cout << YELLOW "\nDEEP COPY TEST\n" RESET;
	std::cout << "\nlet's replace all value of arr4 and compare with arr3\n";
	for (size_t i = 0; i < arr4.size(); ++i)
		manip_array(arr4, d , i); 
	std::cout << "arr4:\n"; std::cout << arr4;
	std::cout << "arr3:\n"; std::cout << arr3;

	std::cout << YELLOW "\nOVER-SIZE TEST\n" RESET;
	std::cout << "\n\n let's create an array of size2 and fill it a bit to much\n";
	Array<T> ar(2);
	for (size_t i = 0; i < 4; ++i)
		manip_array(ar, a, i);
	std::cout << ar;
	std::cout << "\n\n now let's try to copy arr4 to our new array of size 2 (shoudl be dyanmic)\n";
	ar = arr4;
	std::cout << ar;

	std::cout << YELLOW "\nGO CRAZY TEST\n" RESET;
	std::cout << "let's try a ton of wrong index \n";
	manip_array(arr3, a, 42);
	manip_array(arr3, d, -121);
	manip_array(arr3, c, -10000000);
	for (size_t i = 0; i < 8; ++i)
	{
		manip_array(arr1, a, i);
		manip_array(arr2, b, i);
		manip_array(arr3, c , i);
		manip_array(arr4, d, i);
		manip_array(ar, a, i);
	}
	std::cout << arr1;
	std::cout << arr2;
	std::cout << arr3;
	std::cout << ar;
}


int main()
{	
	std::cout << std::endl;
	std::cout << GREEN "/************** INT TEMPLATE TEST *********************/" RESET << std::endl;
	std::cout << std::endl;
	test_array(42, 50, -42, 100000000);
	std::cout << std::endl;
	std::cout << GREEN "/************** DOUBLE TEMPLATE TEST *********************/" RESET << std::endl;
	std::cout << std::endl;
	test_array(42424242.0, -50000.0, -42424242.0, 100000000000000000.0);
	std::cout << std::endl;
	std::cout << GREEN "/************** STRING TEMPLATE TEST *********************/" RESET << std::endl;
	std::cout << std::endl;
	test_array("never", "gonna", "give", "you up");
	return (0);
}