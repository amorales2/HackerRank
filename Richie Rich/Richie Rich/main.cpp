#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void vectorInput(std::vector<int> &vect, int n)
{
	int temp;
	for (int i = 0;i < n; ++i)
	{
		std::cin >> temp;
		vect.push_back(temp);
	}
}

bool checkPalindrome(std::vector<int>& vect)
{
	return equal(vect.begin(), vect.begin() + vect.size() / 2, vect.rbegin());
}

int main()
{
	int n;
	int k;
	std::vector<int> number;


	std::cin >> n >> k;
	std::cin.clear();
	
	while (k)
	{
		//check if we have a palindrome
		--k;
	}

	return 0;
}
