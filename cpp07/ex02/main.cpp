#include "Array.hpp"
#include <iostream>
#include <string>

#define RED "\033[31m"
#define BROWN "\033[33m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main(void)
{
    srand(0);

    std::cout << BROWN << "------ Testing Array of ints ------\n\n" << RESET;

    Array<int> numbers(10);
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = rand();

    std::cout << GREEN << "Array of ints created and filled with random values.\n" << RESET;
    std::cout << numbers << std::endl;

    std::cout << GREEN << "Testing *mirror (subject test)\n" << RESET;
    int* mirror = new int[numbers.size()];
    for (unsigned int i = 0; i < numbers.size(); i++)
        mirror[i] = numbers[i];

    std::cout << "*mirror : " << *mirror << std::endl;

    std::cout << GREEN << "Testing copy constructor\n" << RESET;
    Array<int> copy(numbers);
    std::cout << "Copy:\n";
    std::cout << copy << std::endl;

    std::cout << GREEN << "Testing assignment operator\n" << RESET;
    Array<int> assigned;
    assigned = numbers;
    std::cout << "Assigned:\n";
    std::cout << assigned << std::endl;

    std::cout << RED << "Testing out of bounds access\n" << RESET;
    try
    {
        std::cout << "Index -2:\t";
        std::cout << numbers[-2] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Index Max(" << numbers.size() << "):\t";
        std::cout << numbers[numbers.size()] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    delete[] mirror;

    std::cout << BROWN << "\n------ Testing Array of strings ------\n\n" << RESET;

    Array<std::string> words(5);
    words[0] = "Never";
    words[1] = "gonna";
    words[2] = "give";
    words[3] = "you";
    words[4] = "up";

    std::cout << GREEN << "Array of strings created.\n" << RESET;
    std::cout << words << std::endl;

    std::cout << GREEN << "Testing copy constructor\n" << RESET;
    Array<std::string> copyStr(words);
    std::cout << "Copy:\n";
    std::cout << copyStr << std::endl;

    std::cout << GREEN << "Testing assignment operator\n" << RESET;
    Array<std::string> assignedStr;
    assignedStr = words;
    std::cout << "Assigned:\n";
    std::cout << assignedStr << std::endl;

    std::cout << RED << "Testing out of bounds access\n" << RESET;
    try
    {
        std::cout << "Index -1:\t";
        std::cout << words[-1] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Index Max(" << words.size() << "):\t";
        std::cout << words[words.size()] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << BROWN << "\n------ Testing empty Array ------\n\n" << RESET;
    Array<int> empty;
    std::cout << GREEN << "Empty Array created.\n" << RESET;
    std::cout << empty << std::endl;
    std::cout << RED << "Testing out of bounds access on empty Array\n" << RESET;
    try
    {
        std::cout << "Force access to [0]:\t";
        std::cout << empty[0] << std::endl;
    }
    catch (std::exception& e)    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}