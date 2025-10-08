#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

int main()
{
	std::cout <<BOLD<<YELLOW<< "=== Basic Span Test ===" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout <<CYAN ;
	sp.printNumbers();
	std::cout << RESET;
	std::cout << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << RESET << std::endl;

	std::cout <<BOLD<<YELLOW<< "\n=== Testing with iterator range ===" << RESET << std::endl;
	Span sp2 = Span(10);
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(10);
	numbers.push_back(15);
	numbers.push_back(20);
	
	sp2.addNumber(numbers.begin(), numbers.end());
	std::cout <<CYAN ;
	sp2.printNumbers();
	std::cout << RESET;
	std::cout << "Shortest span: " << sp2.shortestSpan() << RESET << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << RESET << std::endl;

	std::cout <<BOLD<<YELLOW<< "\n=== Testing with large dataset ===" << RESET << std::endl;
	Span sp3 = Span(10000);
	std::vector<int> largeNumbers;
	for (int i = 0; i < 10000; ++i)
		largeNumbers.push_back(i * 2);
	
	sp3.addNumber(largeNumbers.begin(), largeNumbers.end());
	std::cout <<CYAN << "Added 10000 numbers: 0, 2 ,4, ..., 19998" << RESET << std::endl;
	std::cout << "Shortest span: " << sp3.shortestSpan() << RESET << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << RESET << std::endl;

	std::cout <<BOLD<<YELLOW<< "\n=== Testing exceptions ===" << RESET << std::endl;
	Span sp4 = Span(2);
	sp4.addNumber(1);
	sp4.addNumber(2);
	std::cout <<CYAN;
	sp4.printNumbers();
	std::cout <<RESET;
	try {
		sp4.addNumber(3);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << RESET << std::endl;
	}

	Span sp5 = Span(1);
	sp5.addNumber(1);
	
	try {
		std::cout << "Shortest span: " << sp5.shortestSpan() << "❌"<< RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << "✅"<< RESET << std::endl;
	}

	try {
		std::cout << "Longest span: " << sp5.longestSpan() << "❌"<< RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << "✅"<< RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "✅ All tests completed successfully!" << RESET << std::endl;

	return 0;
}
