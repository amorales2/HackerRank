#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
std::string evenOrOdd(int num)
{
	if (num % 2 == 0)
	{
		return "even";
	}
	return "odd";
}
int main()
{
	std::vector<std::string> vect;
	vect.push_back("zero");
	vect.push_back("one");
	vect.push_back("two");
	vect.push_back("three");
	vect.push_back("four");
	vect.push_back("five");
	vect.push_back("six");
	vect.push_back("seven");
	vect.push_back("eight");
	vect.push_back("nine");

	int a, b;
	std::cin >> a >> b;

	for (int i = a;i <= b;++i)
	{
		if (i < 1)
		{
			continue;
		}
		else if (i <= 9)
		{
			std::cout << vect.at(i) << std::endl;
		}
		else
		{
			std::cout << evenOrOdd(i) << std::endl;
		}
	}
	// Complete the code.
	return 0;
}
