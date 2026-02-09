#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
	if (!array || !func)
		return ;
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void printElement(T& element)
{
	std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T& element)
{
	++element;
}
template <typename T>
void toUpperElement(T& element)
{
	for (size_t i = 0; i < element.size(); ++i)
	{
		element[i] = std::toupper(element[i]);
	}
}