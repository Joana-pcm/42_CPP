#include  "Span.hpp"

Span::Span(unsigned int n) : maxSize(n)
{
}

Span::Span(const Span& other) : numbers(other.numbers), maxSize(other.maxSize)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (numbers.size() >= maxSize)
		throw std::runtime_error("Span is full");
	numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());
	return static_cast<unsigned int>(max - min);
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
	os << "\tmaxSize:\t" << span.capacity() << "\n\tNumbers:\t[";
	for (size_t i = 0; i < span.size(); ++i)
	{
		os << span.getNumbers()[i];
		if (i < span.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}