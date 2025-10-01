#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::cout << "=== Basic Span Test ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	sp.printNumbers();
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << "\n=== Testing with iterator range ===" << std::endl;
	Span sp2 = Span(10);
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(10);
	numbers.push_back(15);
	numbers.push_back(20);
	
	sp2.addNumber(numbers.begin(), numbers.end());
	sp2.printNumbers();
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

	std::cout << "\n=== Testing with large dataset ===" << std::endl;
	Span sp3 = Span(10000);
	std::vector<int> largeNumbers;
	for (int i = 0; i < 10000; ++i)
		largeNumbers.push_back(i * 2);
	
	sp3.addNumber(largeNumbers.begin(), largeNumbers.end());
	std::cout << "Added 10000 numbers" << std::endl;
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

	std::cout << "\n=== Testing exceptions ===" << std::endl;
	Span sp4 = Span(2);
	sp4.addNumber(1);
	sp4.addNumber(2);
	
	try {
		sp4.addNumber(3);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Span sp5 = Span(1);
	sp5.addNumber(1);
	
	try {
		std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
