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

    std::vector<Element> elements;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        PmergeMe::Element elem;
        elem.value = vec[i];
        elem.tag = 0; // Initialize tag to 0; it will be set in fordJohnsonSort
        elements.push_back(elem);
    }
	fordJohnsonSort(elements);
    
    for (size_t i = 0; i < elements.size(); ++i)
    {
        vec[i] = elements[i].value; // Update the original vector with sorted values
    }
	_vector = vec;
}

void PmergeMe::sort(std::list<int> &lst)
{
	if (lst.empty())
		throw std::runtime_error("Error: empty list");

    std::vector<Element> elements;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        PmergeMe::Element elem;
        elem.value = *it;
        elem.tag = 0; // Initialize tag to 0; it will be set in fordJohnsonSort
        elements.push_back(elem);
    }
    fordJohnsonSort(elements);
	for (size_t i = 0; i < elements.size(); ++i)
        {lst.remove(elements[i].value);} // Remove the old values
    for (size_t i = 0; i < elements.size(); ++i)
        {lst.push_back(elements[i].value);} // Add the sorted values
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

    size_t prevJacob = 1;
    for (size_t k = 3; order.size() < count; ++k)
    {
        size_t currJacob = jacobsthal(k);
        if (currJacob > count)
            currJacob = count;

        for (size_t idx = currJacob; idx > prevJacob && order.size() < count; --idx)
            order.push_back(idx - 1);

        prevJacob = jacobsthal(k);
        if (prevJacob > count)
            prevJacob = count;
    }
    return order;
}

// Sort a container using the Ford-Johnson algorithm
void PmergeMe::fordJohnsonSort(std::vector<Element> &values)
{
    if (values.size() < 2)
        return;

    typedef Element Elem;
    std::vector<Elem> mainChain;
    std::vector<Elem> pending;
    bool hasLeftover = false;
    Elem leftover;

    size_t nextTag = 0;
    size_t i = 0;
    while (i < values.size())
    {
        if (i + 1 == values.size())
        {
            leftover = values[i];
            hasLeftover = true;
            ++i;
            break;
        }
        Elem first = values[i];
        Elem second = values[i + 1];
        i += 2;
        if (second.value > first.value)
            std::swap(first, second);
        size_t tag = nextTag++;
        first.tag = tag;
        second.tag = tag;
        mainChain.push_back(first);
        pending.push_back(second);
    }

    std::cout << "Main chain: ";
    for (size_t j = 0; j < mainChain.size(); ++j)
        std::cout << mainChain[j].value << " ";
    std::cout << std::endl;

    std::cout << "Pending: ";
    for (size_t j = 0; j < pending.size(); ++j)
        std::cout << pending[j].value << " ";
    std::cout << std::endl;
    std::cout << "Leftover: " << (hasLeftover ? leftover.value : -1) << std::endl;
    // Recursively sort only the chain of winners
    fordJohnsonSort(mainChain);

    // tagToPos[tag] == current index in mainChain of the element with that tag.
    // Tags are 0..nextTag-1, so a vector works as a direct lookup table.
    std::vector<size_t> tagToPos(nextTag);
    for (size_t p = 0; p < mainChain.size(); ++p)
        tagToPos[mainChain[p].tag] = p;

    std::vector<size_t> order = buildInsertionOrder(pending.size());

    for (size_t k = 0; k < order.size(); ++k)
    {
        Elem elem = pending[order[k]];
        size_t boundPos = tagToPos[elem.tag];
        std::vector<Elem>::iterator boundIt = mainChain.begin() + boundPos;

        std::vector<Elem>::iterator insertPos =
            std::lower_bound(mainChain.begin(), boundIt, elem);
        size_t insertIndex = insertPos - mainChain.begin();

        mainChain.insert(insertPos, elem);

        // Shift recorded positions for everything after the insertion point
        for (size_t t = 0; t < tagToPos.size(); ++t)
            if (tagToPos[t] >= insertIndex)
                ++tagToPos[t];
    }

    if (hasLeftover)
    {
        std::vector<Elem>::iterator insertPos =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(insertPos, leftover);
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
