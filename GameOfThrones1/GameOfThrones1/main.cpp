#include <iostream>
#include <string>
#include <algorithm>
#include <map>

bool checkPalindrome(std::string& s)
{
	return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

bool checkIfPalindromePossible(std::string& s)
{
	std::map<char, int> myMap;
	bool centerFound = false;
	int temp = 0;
	for (int i = 0;i < s.length();++i)
	{
		myMap[s[i]] += 1;
		temp = myMap[s[i]];
	}

	for (auto it : myMap)
	{
		if (it.second % 2 == 1)
		{
			if (centerFound == true)
			{
				return false;
			}
			centerFound = true;
		}
	}
	return true;
}

int main()
{
	std::string s;
	std::cin >> s;

	std::sort(s.begin(), s.end());
	if (checkIfPalindromePossible(s))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	return 0;
}