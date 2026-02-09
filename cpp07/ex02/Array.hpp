#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

template <typename T>

class Array
{
private:
	T*      _array;
	size_t  _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();
	Array& operator=(const Array& other);
	size_t size() const;
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	class IndexOutOfBounds : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Index out of bounds";
		}
	};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	os << "Array of size " << arr.size() << ":\n";
	for (size_t i = 0; i < arr.size(); ++i)
	{
		os << "[" << i << "]: " << arr[i] << "\n";
	}
	return os;
}

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
	{
		throw IndexOutOfBounds();
	}
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= _size)
	{
		throw IndexOutOfBounds();
	}
	return _array[index];
}