///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <memory>
#include <vector>

struct node
{
	int nodeNumber;
	int colorValue;
	std::shared_ptr<node> parent{ nullptr };
	std::shared_ptr<node> child{ nullptr };

	node();
	node(int number) :nodeNumber(number) {};



};


int main()
{
	int nodeTotal;
	std::cin >> nodeTotal;
	std::vector<node> tree;


	for (int i = 0; i < nodeTotal; ++i)
	{
		int temp;
		std::cin >> temp;
		tree.push_back(node(temp));
	}

	for (int i = 0; i < nodeTotal - 1; ++i)
	{
		int node1, node2;
		std::cin >> node1 >> node2;

		tree.at(node1).child = std::make_shared<node>(tree.at(node2));
		tree.at(node2).parent = std::make_shared<node>(tree.at(node1));
	}



	return 0;
}