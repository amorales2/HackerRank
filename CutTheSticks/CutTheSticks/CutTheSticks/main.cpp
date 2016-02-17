#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <assert.h>  
using namespace std;
typedef std::vector<int> Sticks;

std::random_device s_rd;
std::mt19937 s_randomGenerator(s_rd());

// Produces the same results every run for debugging.
std::mt19937 s_testGenerator(0);

//---------------------------------------------------------
// Test functions
//---------------------------------------------------------

int GetRandomInt_TEST(int lowerBound, int upperBound)
{
	std::uniform_int_distribution<int> dist(lowerBound, upperBound);
	return dist(s_testGenerator);
}

Sticks GenerateSticks_TEST(int size)
{
	Sticks sticks(size);
	std::generate(sticks.begin(), sticks.end(), []() { return GetRandomInt_TEST(1, 1000); });
	return sticks;
}

void Output_TEST(Sticks sticks)
{
	int numZeros = std::count(sticks.begin(), sticks.end(), 0);
	int test1 = std::count_if(sticks.begin(), sticks.end(), [](int stick) {return stick != 0; });
	assert(numZeros == sticks.size());
}

void run(Sticks &sticks)
{
	//std sort on sticks. O(N*log(n)) N distance from begin to end
	sort(sticks.begin(), sticks.end());
	
	while (sticks.size() > 1)
	{
		cout << sticks.size() << endl;
		//loop through sticks and re.duce all values by the first value
		for (int i = sticks.size() - 1; i > 0; --i)
		{
			if (sticks.at(0) >= sticks.at(i))
			{
				//erase all items in vector from beginning to the current location
				sticks.erase(sticks.begin(), sticks.begin() + i + 1);
				break; //we are finished with the operation
			}
			else
			{
				//subtract the stick size by the smallest stick (at the front of the vector)
				sticks.at(i) -= sticks.at(0);
				if (i == 1)
				{
					sticks.erase(sticks.begin());
					break;
				}
			}
		}//end for
	}//end while
}
void betterRun(Sticks &sticks)
{
	//std sort on sticks. O(N*log(n)) N distance from begin to end
	sort(sticks.rbegin(), sticks.rend());

	int temp = 0;
	while (sticks.size() > 1)
	{
		cout << sticks.size() << endl;
		temp = sticks.back();

		//loop through sticks and reduce all values by the last value
		for (int i = 0; i < sticks.size(); ++i)
		{
			if (temp >= sticks.at(i))
			{
				//erase all items in vector from the current location to the end
				
				sticks.erase(sticks.begin() + i,sticks.end());
				break; //we are finished with the operation
			}
			else
			{
				//subtract the stick size by the smallest stick (at the front of the vector)
				sticks.at(i) -= temp;
				if (i == sticks.size()-2)
				{
					sticks.pop_back();
					break;
				}
			}
		}//end for
	}//end while
}

int main()
{
	int NumberOfSticks;
	Sticks sticks;

	//vector with 1 million elements
	sticks = GenerateSticks_TEST(1000000);
	betterRun(sticks);
	Output_TEST(sticks);

	return 0;
}