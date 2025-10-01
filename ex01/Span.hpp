#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	template<typename Iterator>
	void addNumber(Iterator begin, Iterator end)
	{
		unsigned int distance = std::distance(begin, end);
		if (_numbers.size() + distance > _maxSize)
			throw std::runtime_error("Adding these numbers would exceed Span capacity");
		_numbers.insert(_numbers.end(), begin, end);
	}
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	unsigned int size() const;
	void printNumbers() const;
};

#endif
