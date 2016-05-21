
#include <vector>
#include <iostream>

typedef unsigned long long ull;

void printAnswer(ull num)
{
	//not sure what this number is supposed to be
	ull wtf = pow(10, 9);

	std::cout << num % (wtf + 7);

}

ull factorial(ull num)
{
	ull temp = 1;
	for (int i = num;i > 1;--i)
	{
		temp *= i;
	}
	return temp;
}

ull combinations(ull n, ull r)
{
	ull top = factorial(n);
	// -----------------------------
	ull bottom = factorial(r) * factorial(n - r);
	return top / bottom;
}

void changeBatallionsToDetachments(std::vector<ull> &vect)
{
	for (auto it = vect.begin();it != vect.end();++it)
	{

		if (*it < 4)
		{
			//1 is for an empty set
			*it = 1;
		}
		else
		{
			//4 being size of detachment. 
			//Add one for the empty set case
			*it = combinations(*it, 4) + 1;
		}
	}
}

void calculateAllPossibleCombinations()
{

}


int main()
{
	ull number_of_battallions;
	ull number_of_countries;
	std::cin >> number_of_battallions >> number_of_countries;

	std::vector<ull> batallions(number_of_battallions);
	std::vector<ull> combinations( combinations( number_of_battallions, number_of_countries ) );

	//set number of soldiers for the vector of batallions
	for (auto it = batallions.begin();it != batallions.end();++it)
	{
		std::cin >> *it;
	}

	changeBatallionsToDetachments(batallions);

	printAnswer(20);



	return 0;
}