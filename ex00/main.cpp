#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
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
	std::cout << BOLD << YELLOW << "=== Testing easyfind with vector ===" << RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::cout <<MAGENTA<<"vector:";
	for(size_t i=0;i<vec.size();i++){
		std::cout <<" "<<vec[i];
	}
	std::cout <<RESET<< std::endl;
	std::cout << "Found value 3 "<<std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "at position: " << std::distance(vec.begin(), it) << RESET << std::endl;
		std::cout << "Value: " << *it << "✅"<< RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "❌"<< RESET << std::endl;
	}

	std::cout << "\nFound value 6 "<<std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "at position: " << std::distance(vec.begin(), it) << "❌"<< RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "✅"<< RESET << std::endl;
	}

	std::cout << BOLD << YELLOW << "\n=== Testing easyfind with list ===" << RESET << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	std::cout <<MAGENTA<< "list:";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    std::cout << " " << *it;

	std::cout <<RESET<< std::endl;
	std::cout << "Found value 20 "<<std::endl;
	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Value: " << *it << "✅"<< RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "❌"<< RESET << std::endl;
	}
	std::cout << "\nFound value 50 "<<std::endl;
	try {
		easyfind(lst, 50);
		std::cout << "❌"<< RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "✅"<< RESET << std::endl;
	}

	std::cout << BOLD << YELLOW << "\n=== Testing easyfind with deque ===" << RESET << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);
	std::cout <<MAGENTA<< "deque:";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    std::cout << " " << *it;

	std::cout <<RESET<< std::endl;
	std::cout << "Found value 200"<<std::endl;
	try {
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Value: " << *it << "✅"<< RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "❌"<< RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "✅ All tests completed successfully!" << RESET << std::endl;

	return 0;
}
