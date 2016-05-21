//////////////////////////////////////////////////
//main.cpp
//

//Project Euler #1: Multiples of 3 and 5
/*

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get
3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below NN.

Input Format
First line contains TT that denotes the number of test cases.
This is followed by TT lines, each containing an integer, NN.

Output Format
For each test case, print an integer that denotes the sum of
all the multiples of 3 or 5 below NN.


Sample Input
---------------------
2
10
100

Sample Output
---------------------
23
2318

*/

#include <iostream>
int main()
{
	long numberOfTests = 0;
	long currentTestNumber = 0;
	long threeTotal = 0;
	long fiveTotal = 0;
	long fifteenTotal = 0;

	std::cin >> numberOfTests;

	do
	{
		std::cin >> currentTestNumber;
		threeTotal = (currentTestNumber - 1) / 3;
		fiveTotal = (currentTestNumber - 1) / 5;
		fifteenTotal = (currentTestNumber - 1) / 15;

		//add in the multiples of 3 and 5. 
		//subtract out the multiples of 15 (thoes shared with 3 and 5)
		std::cout << 3 * (threeTotal*(threeTotal + 1) / 2) + 
			5 * (fiveTotal*(fiveTotal + 1) / 2) - 
			15 * (fifteenTotal*(fifteenTotal + 1) / 2) << std::endl;

	} while (--numberOfTests);

	return 0;
}