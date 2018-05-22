#include<iostream>
#include<bits/stdc++.h>
#include<list>
#define NIL -1
#include<stdexcept>


using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;    // Number of vertices
    list<int> *adjacencyLists;
    void searchBridges(int v, bool visited[], int disc[], int low[],
                       int parent[]);
    int length;

public:
    Graph(int V):
        length(0)
    {
        if(V <= 0)
            throw length_error("Incorrect graph");
        this->V = V;
        adjacencyLists  = new list<int>[(V*(V-1))/2];
    }
    int size()
    {
        return length;
    };
    void addEdge(int v, int w);   // to add an edge to graph
    void printBridges();    // prints all bridges
};
