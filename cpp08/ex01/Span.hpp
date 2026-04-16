#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int> numbers;
		unsigned int maxSize;
	public:
		Span(unsigned int n);	
		Span(const Span& other);
		~Span();
		Span& operator=(const Span& other);
		void addNumber(int number);
		template <typename InputIt>
		void addNumbers(InputIt first, InputIt last)
		{
			while (first != last)
			{
				addNumber(*first);
				++first;
			}
		}
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int size() const { return numbers.size(); }
		unsigned int capacity() const { return maxSize; }
		std::vector<int> getNumbers() const { return numbers; }
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

std::ostream& operator<<(std::ostream& os, const Span& span);