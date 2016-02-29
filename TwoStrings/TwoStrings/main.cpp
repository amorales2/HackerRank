#include <iostream>
#include <map>
#include <string>


bool isCommonSubstr(std::string &s1, std::string &s2)
{
	std::map<char, int> myMap;

	//map out first string
	for (int i = 0;i < s1.length();++i)
	{
		myMap[s1[i]]++;
	}

	//check map for each character of second string
	for (int i = 0;i < s2.length(); ++i)
	{
		auto it = myMap.find(s2[i]);
		if (it != myMap.end())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int numberOfTests;
	std::cin >> numberOfTests;
	while (numberOfTests--)
	{
		//take in two strings as user input
		std::string s1, s2;
		std::cin >> s1 >> s2;
		if (isCommonSubstr(s1, s2))
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}

	return 0;
}