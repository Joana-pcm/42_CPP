#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _list(other._list) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_list = other._list;
	}
	return (*this);
}

void PmergeMe::sort(std::vector<int> &vec)
{
	if (vec.empty())
		throw std::runtime_error("Error: empty vector");

	fordJohnsonSort(vec);
	_vector = vec;
}

void PmergeMe::sort(std::list<int> &lst)
{
	if (lst.empty())
		throw std::runtime_error("Error: empty list");

	fordJohnsonSort(lst);
	_list = lst;
}

// Calculate the Jacobsthal number for a given index
// Jacobsthal is a sequence where each term is the 
// sum of the previous term and twice the term before that
size_t PmergeMe::jacobsthal(size_t index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;

	size_t previous = 0;
	size_t current = 1;
	for (size_t i = 2; i <= index; ++i)
	{
		size_t next = current + (previous * 2);
		previous = current;
		current = next;
	}
	return current;
}

// use buildInsertionOrder to determine the order in which elements should be inserted
std::vector<size_t> PmergeMe::buildInsertionOrder(size_t count)
{
	std::vector<size_t> order;

	if (count == 0)
		return order;
	order.push_back(0);
	if (count == 1)
		return order;

	size_t previousBoundary = 1;
	for (size_t level = 3; order.size() < count; ++level)
	{
		size_t currentBoundary = jacobsthal(level);
		if (currentBoundary > count)
			currentBoundary = count;
		for (size_t index = currentBoundary; index > previousBoundary && order.size() < count; --index)
			order.push_back(index - 1);
		previousBoundary = currentBoundary;
	}
	return order;
}

// Sort a container using the Ford-Johnson algorithm
template <typename Container>
void PmergeMe::fordJohnsonSort(Container &values)
{
	// will return and end the recursion sequence
	if (values.size() < 2)
		return ;

	typedef typename Container::value_type value_type;
	Container mainChain;
	std::vector<value_type> pending;

	for (typename Container::iterator it = values.begin(); it != values.end();)
	{

		value_type first = *it;
		++it;
		if (it == values.end())
		{
			pending.push_back(first);
			break;
		}

		value_type second = *it;
		++it;

		if (second > first)
			std::swap(first, second);
		mainChain.push_back(first);
		pending.push_back(second);
	}
/* 	std::cout << "Main chain: ";
	for (typename Container::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Pending: ";
	for (typename std::vector<value_type>::iterator it = pending.begin(); it != pending.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl; */
	// use recursion
	// until it reaches the end if the mainChain
	fordJohnsonSort(mainChain);

	std::vector<size_t> order = buildInsertionOrder(pending.size());
/* 
	std::cout << "Insertion order: ";
	for (size_t i = 0; i < order.size(); ++i)
		std::cout << order[i] << " "; */
	std::cout << std::endl;
	for (size_t i = 0; i < order.size(); ++i)
	{
		typename Container::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), pending[order[i]]);
		mainChain.insert(position, pending[order[i]]);
	}

	values.swap(mainChain);
}

void PmergeMe::printVector() const
{
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList() const
{
	for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}