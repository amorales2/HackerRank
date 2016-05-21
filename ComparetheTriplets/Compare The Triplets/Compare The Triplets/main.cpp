#include <iostream>

int main() {
	int a0;
	int a1;
	int a2;
	std::cin >> a0 >> a1 >> a2;
	int b0;
	int b1;
	int b2;
	std::cin >> b0 >> b1 >> b2;

	int totala = 0;
	int totalb = 0;
	if (a0 > b0)
	{
		++totala;
	}
	if (a1 > b1)
	{
		++totala;
	}
	if (a2 > b2)
	{
		++totala;
	}

	//bob
	if (a0 < b0)
	{
		++totalb;
	}
	if (a1 < b1)
	{
		++totalb;
	}
	if (a2 < b2)
	{
		++totalb;
	}
	std::cout << totala << " " << totalb << std::endl;
	return 0;
}
