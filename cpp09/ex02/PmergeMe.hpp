#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <climits>

class PmergeMe
{
private:
	std::vector<int>	_vector;
	std::list<int>		_list;
	size_t				_idCount; // total number of elements in the original input
public:
	// constructors
	PmergeMe();
	template <typename Container>
	PmergeMe(Container &values);
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	// template struct to hold a value and its associated tag
    struct Element
    {
        int value;
        size_t id;
        bool operator<(const Element &other) const { return value < other.value; }
    };

	// methods
	void sort(std::vector<int> &vec);
	void sort(std::list<int> &lst);
	size_t jacobsthal(size_t index);
	void fordJohnsonSort(std::vector<Element> &values);
	std::vector<size_t> buildInsertionOrder(size_t count);

	// getters for the whole container
	void printVector() const;
	void printList() const;
};
