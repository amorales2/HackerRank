#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	std::string time;
	std::cin >> time;

	std::string newTime;


	int temp = (time.at(0) - 48) * 10 + (time.at(1) - 48);

	if (time[8] == 'P' && temp != 12)
	{
		//convert time from 12hrampm to 24hr
		temp += 12;

		//rebuild string and print
		newTime = std::to_string(temp) + time.substr(2, 6);
	}
	//case for midnight
	else if (time[8] == 'A' && temp == 12)
	{
		//rebuild string and print
		newTime = "00" + time.substr(2, 6);
	}
	else
	{
		//rebuild string and print
		newTime = time.substr(0, 8);
	}

	std::cout << newTime;
	return 0;
}