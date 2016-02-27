///////////////////////////////////////////////////////////////////////////////
//
//main.cpp
//


/*
Given a graph consisting NN nodes (labelled 1 to N) where a specific given 
node SS represents the starting position SS and an edge between two nodes is 
of a given length, which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position 
(Node S) to all of the other nodes in the graph.

Note 1: If a node is unreachable , the distance is assumed as −1−1.

///////////////////////////////////////////////////////////////////////////////
Input Format

The first line contains TT, denoting the number of test cases.
First line of each test case has two integers NN, denoting the number of nodes 
in the graph and MM, denoting the number of edges in the graph.

The next MM lines each consist of three space-separated integers xx yy rr, where
xx and yy denote the two nodes between which the undirected edge exists, rr 
denotes the length of edge between these corresponding nodes.

The last line has an integer SS, denoting the starting position.
*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>


struct Node;

//an edge contains its length, startpoint, and endpoint.
//edges are directional
struct Edge
{
	int m_edgeLength;
	std::shared_ptr<Node> m_startPoint;
	std::shared_ptr<Node> m_endPoint;

	Edge(int edgeLength,const Node& startPoint, const Node& endPoint)
	{
		m_edgeLength = edgeLength;
		m_endPoint = std::make_shared<Node>(endPoint);
		m_startPoint = std::make_shared<Node>(startPoint);
	};

};

//A node is a point on the graph
struct Node
{
	int m_name;
	Node(int name)
	{
		m_name = name;
	}
};

//the graph is a collection of nodes. The nodes themselves contain the edges.
struct Graph
{
	std::vector<Node> m_nodeList;
	std::vector<Edge> m_edgeList;
	void addNode(int name)
	{		
		m_nodeList.push_back(Node(name));
	}
	void addEdge(int edgeLength, const Node& startPoint, const Node& endPoint)
	{
		m_edgeList.push_back(Edge(edgeLength, startPoint, endPoint));
	}
};

void dijkstra(const Graph& graph, int node)
{
	//TODO
}

int main()
{
	//take in number of tests
	int numberOfTests;
	std::cin >> numberOfTests;

	int numberOfNodes;
	int numberOfEdges;

	Graph graph;

	//main loop
	do
	{
	//user input for the test
		//number of nodes
		std::cin >> numberOfNodes;
		
		//number of edges
		std::cin >> numberOfEdges;

		//populate graph with number of nodes
		for (int i = 0;i < numberOfNodes; ++i)
		{
			graph.addNode(i);
		}
		//loop through number of edges
		for (int i = 0;i < numberOfEdges; ++i)
		{
			//get start,end, and length from user and add to graph
			int start, end, length;
			std::cin >> start >> end >> length;
			graph.addEdge(length,start,end);
		}
		

	//run Dijkstras shortest path algorithm for edge from user input
		int node;
		std::cin >> node;
		dijkstra(graph, node);
	//print shortest path from edge to all other edges

	} while (--numberOfTests);

	return 0;
}
