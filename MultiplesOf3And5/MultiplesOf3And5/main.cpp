#include <iostream>

int main()
{
	int numberOfTests;
	std::cin >> numberOfTests;

	long long currentTest;
	long long currentTotal = 0;
	while (numberOfTests--)
	{
		std::cin >> currentTest;
		for (long i = 1; i < currentTest; ++i)
		{
			if (i % 3 == 0 || i % 5 == 0)
			{
				currentTotal += i;
			}
		}
		std::cout << currentTotal << std::endl;
		
		//clear current total for next test
		currentTotal = 0;
	}

	return 0;
}
