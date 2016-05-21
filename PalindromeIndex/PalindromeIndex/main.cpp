#include <iostream>
#include <string>
#include <algorithm>
#include <map>

bool checkPalindrome(std::string& s)
{
	return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

int main()
{
	int numberOfTests;
	std::cin >> numberOfTests;

	
	while (numberOfTests--)
	{
		//string input 
		std::string s;
		std::cin >> s;
		
		if (checkPalindrome(s))
		{
			std::cout << -1;
		}
		else
		{
			for (int i = 0;i < s.length();++i)
			{
				std::string tempString = s;
				tempString.erase(tempString.begin() + i);
				if (checkPalindrome(tempString))
				{
					std::cout << i << std::endl;
					break;
				}
			}
		}
	}


	return 0;
}