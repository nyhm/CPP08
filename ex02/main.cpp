#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== Testing MutantStack ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\n=== Iterating through MutantStack ===" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n=== Testing with std::stack ===" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "std::stack size: " << s.size() << std::endl;
	std::cout << "std::stack top: " << s.top() << std::endl;

	std::cout << "\n=== Testing reverse iteration ===" << std::endl;
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
	std::cout << std::endl;

	std::cout << "\n=== Testing with different data types ===" << std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	stringStack.push("C++");
	stringStack.push("STL");

	std::cout << "String stack contents: ";
	for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != stringStack.end())
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "\n=== Testing const iteration ===" << std::endl;
	const MutantStack<int> constStack = mstack;
	std::cout << "Const stack contents: ";
	for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != constStack.end())
			std::cout << ", ";
	}
	std::cout << std::endl;

	return 0;
}
