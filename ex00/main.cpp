#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
	std::cout << "=== Testing easyfind with vector ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found value 3 at position: " << std::distance(vec.begin(), it) << std::endl;
		std::cout << "Value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Found value 6 at position: " << std::distance(vec.begin(), it) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing easyfind with list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found value 20 in list" << std::endl;
		std::cout << "Value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		easyfind(lst, 50);
		std::cout << "Found value 50 in list" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing easyfind with deque ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try {
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found value 200 in deque" << std::endl;
		std::cout << "Value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
