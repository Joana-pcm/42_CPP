#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::list<int> _list;
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	void sort(std::vector<int> &vec);
	void sort(std::list<int> &lst);
	size_t jacobsthal(size_t index);
	template <typename Container>
	void fordJohnsonSort(Container &values);
	std::vector<size_t> buildInsertionOrder(size_t count);
	void printVector() const;
	void printList() const;
};

