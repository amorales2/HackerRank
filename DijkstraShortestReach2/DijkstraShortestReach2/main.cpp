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

//an edge contains its length and its endpoint. The starting point is 
//the object that owns the edge.
struct edge
{
	int m_edgeLength;
	std::shared_ptr<node> m_endpoint;

	const edge(int edgeLength, const node& const endpoint)
	{
		m_edgeLength = edgeLength;
		m_endpoint = std::make_shared<node>(endpoint);
	};

};

//A node is a collection of edges.
struct node
{
	std::vector<edge> m_edgeList;
	
	void addEdge(int edgelength,const node& const endpoint)
	{
		m_edgeList.push_back(edge(edgelength, endpoint));
	}

	void addTwoWayEdge(int edgelength, node& const endpoint)
	{
		m_edgeList.push_back(edge(edgelength, endpoint));
		endpoint.addEdge(edgelength, *this);
	}
};

//the graph is a collection of nodes. The nodes themselves contain the edges.
struct graph
{
	std::vector<node> m_nodeList;
	void addNode(const node& node)
	{
		m_nodeList.push_back(node);
	}

};


int main()
{

	return 0;
}