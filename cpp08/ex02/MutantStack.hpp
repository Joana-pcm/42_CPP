#pragma once 

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		MutantStack() {}
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		~MutantStack() {}
		MutantStack& operator=(const MutantStack& other)
		{
			std::stack<T>::operator=(other);
			return *this;
		}
		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
		const_iterator begin() const { return std::stack<T>::c.begin(); }
		const_iterator end() const { return std::stack<T>::c.end(); }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& mstack)
{
	os << "MutantStack with " << mstack.size() << " element" << (mstack.size() == 1 ? "" : "s") << ":\t[";
	for (typename MutantStack<T>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		os << *it << (it + 1 != mstack.end() ? ", " : "");
	}
	os << "]\n";
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& mstack)
{
	os << "List with " << mstack.size() << " element" << (mstack.size() == 1 ? "" : "s") << ":\t[";
	for (typename std::list<T>::const_iterator it = mstack.begin(); it != mstack.end(); )
	{
		os << *it << (++it != mstack.end() ? ", " : "");
	}
	os << "]\n";
	return os;
}