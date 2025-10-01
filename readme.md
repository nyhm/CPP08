要件　https://cdn.intra.42.fr/pdf/pdf/173712/en.subject.pdf

https://web.archive.org/web/20250429115023/https://42-evaluation-sheets-hub.vercel.app/Cursus/CPP08/


Compiling
• Compile your code with c++ and the flags -Wall -Wextra -Werror
• Your code should still compile if you add the flag -std=c++98
Formatting and naming conventions
• The exercise directories will be named this way: ex00, ex01, ... , exn
• Name your files, classes, functions, member functions and attributes as required in
the guidelines.
• Write class names in UpperCamelCase format. Files containing class code will
always be named according to the class name. For instance:
ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp. Then, if you
have a header file containing the definition of a class "BrickWall" standing for a
brick wall, its name will be BrickWall.hpp.
• Unless specified otherwise, every output message must end with a newline character
and be displayed to the standard output.
• Goodbye Norminette! No coding style is enforced in the C++ modules. You can
follow your favorite one. But keep in mind that code your peer evaluators can’t
understand is code they can’t grade. Do your best to write clean and readable code.
Allowed/Forbidden
You are not coding in C anymore. Time to C++! Therefore:
• You are allowed to use almost everything from the standard library. Thus, instead
of sticking to what you already know, it would be smart to use the C++-ish versions
of the C functions you are used to as much as possible.
• However, you can’t use any other external library. It means C++11 (and derived
forms) and Boost libraries are forbidden. The following functions are forbidden
too: *printf(), *alloc() and free(). If you use them, your grade will be 0 and
that’s it.

• Note that unless explicitly stated otherwise, the using namespace <ns_name> and
friend keywords are forbidden. Otherwise, your grade will be -42.
• You are allowed to use the STL only in Modules 08 and 09. That means:
no Containers(vector/list/map, and so forth) and no Algorithms(anything that
requires including the <algorithm> header) until then. Otherwise, your grade will
be -42.
A few design requirements
• Memory leakage occurs in C++ too. When you allocate memory (by using the new
keyword), you must avoid memory leaks.
• From Module 02 to Module 09, your classes must be designed in the Orthodox
Canonical Form, except when explicitly stated otherwise.
• Any function implementation put in a header file (except for function templates)
means 0 to the exercise.
• You should be able to use each of your headers independently from others. Thus,
they must include all the dependencies they need. However, you must avoid the
problem of double inclusion by adding include guards. Otherwise, your grade will
be 0.
Read me
• You can add some additional files if you need to (i.e., to split your code). As these
assignments are not verified by a program, feel free to do so as long as you turn in
the mandatory files.
• Sometimes, the guidelines of an exercise look short but the examples can show
requirements that are not explicitly written in the instructions.
• Read each module completely before starting! Really, do it.
• By Odin, by Thor! Use your brain!!!
Regarding the Makefile for C++ projects, the same rules as in C apply
(see the Norm chapter about the Makefile).
You will have to implement a lot of classes. This can seem tedious,
unless you’re able to script your favorite text editor.

You are given a certain amount of freedom to complete the exercises.
However, follow the mandatory rules and don’t be lazy. You would
miss a lot of useful information! Do not hesitate to read about
theoretical concepts.

Chapter III
Module-specific rules
You will notice that, in this module, the exercises can be solved WITHOUT the standard
Containers and WITHOUT the standard Algorithms.
However, using them is precisely the goal of this Module.
You must use the STL — especially the Containers (vector/list/map/and so forth)
and the Algorithms(defined in header <algorithm>) — whenever they are appropriate.
Moreover, you should use them as much as you can.
Thus, do your best to apply them wherever it’s appropriate.
You will get a very bad grade if you don’t, even if your code works as expected. Please
don’t be lazy.
You can define your templates in the header files as usual. Or, if you want to, you
can write your template declarations in the header files and write their implementations
in .tpp files. In any case, the header files are mandatory while the .tpp files are optional.

Exercise 00: Easy find
Exercise : 00
Easy find
Turn-in directory: ex00/
Files to turn in: Makefile, main.cpp, easyfind.{h, hpp}
and optional file: easyfind.tpp
Forbidden functions: None
A first easy exercise is the way to start off on the right foot.
Write a function template easyfind that accepts a type T. It takes two parameters:
the first one is of type T, and the second one is an integer.
Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.
If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.
Of course, implement and turn in your own tests to ensure everything works as ex-
pected.
You don’t have to handle associative containers.

Chapter VI
Exercise 01: Span
Exercise : 01
Span
Turn-in directory: ex01/
Files to turn in: Makefile, main.cpp, Span.{h, hpp}, Span.cpp
Forbidden functions: None
Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.
This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.
Next, implement two member functions: shortestSpan() and longestSpan()
They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.
Of course, you will write your own tests, and they will be far more thorough than the
ones below. Test your Span with at least 10,000 numbers. More would be even better.


Running this code:
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
Should output:
$> ./ex01
2
14
$>
Last but not least, it would be wonderful to fill your Span using a range of iterators.
Making thousands of calls to addNumber() is so annoying. Implement a member function
to add multiple numbers to your Span in a single call.
If you don’t have a clue, study the Containers. Some member
functions take a range of iterators in order to add a sequence of
elements to the container.

Chapter VII
Exercise 02: Mutated abomination
Exercise : 02
Mutated abomination
Turn-in directory: ex02/
Files to turn in: Makefile, main.cpp, MutantStack.{h, hpp}
and optional file: MutantStack.tpp
Forbidden functions: None
Now, it’s time to move on to more serious things. Let’s develop something weird.
The std::stack container is very nice. Unfortunately, it is one of the only STL Con-
tainers that is NOT iterable. That’s too bad.
But why would we accept this? Especially if we can take the liberty of butchering the
original stack to create missing features.
To repair this injustice, you have to make the std::stack container iterable.
Write a MutantStack class. It will be implemented in terms of a std::stack.
It will offer all its member functions, plus an additional feature: iterators.
Of course, you will write and turn in your own tests to ensure everything works as
expected.


Find a test example below.
int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}
If you run it a first time with your MutantStack, and a second time replacing the
MutantStack with, for example, a std::list, the two outputs should be the same. Of
course, when testing another container, update the code below with the corresponding
member functions (push() can become push_back()).
////////////


SCALE FOR PROJECT CPP MODULE 08
You should evaluate 1 student in this team

Introduction
Please comply with the following rules:

- Remain polite, courteous, respectful and constructive throughout the
evaluation process. The well-being of the community depends on it.

- Identify with the student or group whose work is evaluated the possible
dysfunctions in their project. Take the time to discuss and debate the
problems that may have been identified.

- You must consider that there might be some differences in how your peers
might have understood the project's instructions and the scope of its
functionalities. Always keep an open mind and grade them as honestly as
possible. The pedagogy is useful only and only if the peer-evaluation is
done seriously.

Guidelines
- Only grade the work that was turned in the Git repository of the evaluated
student or group.

- Double-check that the Git repository belongs to the student(s). Ensure that
the project is the one expected. Also, check that 'git clone' is used in an
empty folder.

- Check carefully that no malicious aliases was used to fool you and make you
evaluate something that is not the content of the official repository.

- To avoid any surprises and if applicable, review together any scripts used
to facilitate the grading (scripts for testing or automation).

- If you have not completed the assignment you are going to evaluate, you have
to read the entire subject prior to starting the evaluation process.

- Use the available flags to report an empty repository, a non-functioning
program, a Norm error, cheating, and so forth.
In these cases, the evaluation process ends and the final grade is 0,
or -42 in case of cheating. However, except for cheating, student are
strongly encouraged to review together the work that was turned in, in order
to identify any mistakes that shouldn't be repeated in the future.

- You should never have to edit any file except the configuration file if it
exists. If you want to edit a file, take the time to explicit the reasons
with the evaluated student and make sure both of you are okay with this.

- You must also verify the absence of memory leaks. Any memory allocated on
the heap must be properly freed before the end of execution.
You are allowed to use any of the different tools available on the computer,
such as leaks, valgrind, or e_fence. In case of memory leaks, tick the
appropriate flag.

Attachments
 subject.pdf
Preliminary tests
If cheating is suspected, the evaluation stops here. Use the "Cheat" flag to report it. Take this decision calmly, wisely, and please, use this button with caution.

Prerequisites

The code must compile with c++ and the flags -Wall -Wextra -Werror
Don't forget this project has to follow the C++98 standard. Thus,
C++11 (and later) functions or containers are NOT expected.

Any of these means you must not grade the exercise in question:

A function is implemented in a header file (except for template functions).
A Makefile compiles without the required flags and/or another compiler than c++.
Any of these means that you must flag the project with "Forbidden
Function":

Use of a "C" function (*alloc, *printf, free).
Use of a function not allowed in the exercise guidelines.
Use of "using namespace <ns_name>" or the "friend" keyword.
Use of an external library, or features from versions other than C++98.
 Yes
 No
Ex00: Easy find
As usual, there has to be the main function that contains enough tests to prove the program works as expected. If there isn't, do not grade this exercise. If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

Template function

There is a templated function easyFind(T, int) that does what the
subject requires.
It HAS to use STL algorithms.
If it does not (like manual search using iterators for example), count
it as wrong.

 Yes
 No
Ex01: Span
As usual, there has to be the main function that contains enough tests to prove the program works as expected. If there isn't, do not grade this exercise. If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

Class and member functions

There is a class that complies with the constraints of the subject.
Its member functions use STL algorithms to find their result as much as
possible. Finding the shortest span can't be done only by subtracting
the two lowest numbers (take a closer look at the subject example).

 Yes
 No
Improved addNumber function

There's a way to add numbers that's more practical than calling the
addNumber() function repeatedly.

 Yes
 No
Ex02: Mutated abomination
As usual, there has to be the main function that contains enough tests to prove the program works as expected. If there isn't, do not grade this exercise. If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

MutantStack class

There is a MutantStack class that inherits from std::stack and offers
all of its member functions.
It has an iterator. Also, it is possible to do at least the operations
shown in the subject's examples using iterators.

 Yes
 No
Better tests

There is a at least a main() function that has more tests than the ones
from the subject.

 Yes
 No
Ratings
Don’t forget to check the flag corresponding to the defense
 Ok
 Outstanding project
 Empty work
 Incomplete work
 Invalid compilation
 Cheat
 Crash
 Concerning situation
 Leaks
 Forbidden function
Conclusion

 