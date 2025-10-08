#include "MutantStack.hpp"
#include <iostream>
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
	std::cout <<BOLD<<YELLOW<< "=== Testing MutantStack ===" << RESET<< std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << RESET<< std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << RESET<< std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout <<BOLD<<YELLOW<< "\n=== Iterating through MutantStack ===" << RESET<< std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << RESET<< std::endl;
		++it;
	}

	std::cout <<BOLD<<YELLOW<< "\n=== Testing with std::stack ===" << RESET<< std::endl;
	std::stack<int> s(mstack);
	std::cout << "std::stack size: " << s.size() << RESET<< std::endl;
	std::cout << "std::stack top: " << s.top() << RESET<< std::endl;

	std::cout <<BOLD<<YELLOW<< "\n=== Testing reverse iteration ===" << RESET<< std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << "Reverse order: ";
	while (rit != rite)
	{
		std::cout << *rit;
		++rit;
		if (rit != rite)
			std::cout << ", ";
	}
	std::cout << RESET<< std::endl;

	std::cout <<BOLD<<YELLOW<< "\n=== Testing with different data types ===" << RESET<< std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("Hey");
	stringStack.push("I");
	stringStack.push("am");
	stringStack.push("hnagashi");

	std::cout << "String stack contents: ";
	for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != stringStack.end())
			std::cout << " ";
	}
	std::cout << RESET<< std::endl;

	std::cout <<BOLD<<YELLOW<< "\n=== Testing const iteration ===" << RESET<< std::endl;
	const MutantStack<int> constStack = mstack;
	std::cout << "Const stack contents: ";
	for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != constStack.end())
			std::cout << ", ";
	}
	std::cout << RESET<< std::endl;

	return 0;
}
