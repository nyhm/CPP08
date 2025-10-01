#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full, cannot add more numbers");
	_numbers.push_back(number);
}


unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Need at least 2 numbers to calculate span");
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	
	unsigned int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Need at least 2 numbers to calculate span");
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	
	return sorted.back() - sorted.front();
}

unsigned int Span::size() const
{
	return _numbers.size();
}

void Span::printNumbers() const
{
	std::cout << "Numbers in Span: ";
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != _numbers.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}
