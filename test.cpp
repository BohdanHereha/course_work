#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Graphs.h"

using namespace std;

TEST_CASE("Searching for a bridge in the graph 1")
{
    list<int> *adjacencyLists;
    Graph graph1 = Graph(5);
    graph1.addEdge(1, 0);
    graph1.addEdge(0, 2);
    graph1.addEdge(2, 1);
    graph1.addEdge(0, 3);
    graph1.addEdge(3, 4);
    CHECK(graph1.size() == 5);
    REQUIRE_NOTHROW(graph1.printBridges()); // 3,4 // 0,3
};

TEST_CASE("Searching for a bridge in the graph 2")
{
    list<int> *adjacencyLists;
    Graph graph2 = Graph(4);
    graph2.addEdge(0, 1);
    graph2.addEdge(1, 2);
    graph2.addEdge(2, 3);
    CHECK(graph2.size() == 3);
    REQUIRE_NOTHROW(graph2.printBridges());  // 2, 3 // 1, 2 // 0,1
};

TEST_CASE("Searching for a bridge in the graph 3")
{
    list<int> *adjacencyLists;
    Graph graph3 = Graph(4);
    graph3.addEdge(1, 0);
    graph3.addEdge(1, 3);
    graph3.addEdge(3, 2);
    graph3.addEdge(0, 2);
    CHECK(graph3.size() == 4);
    REQUIRE_NOTHROW(graph3.printBridges()); // no bridges
};

TEST_CASE("Searching for a bridge in the graph 4")
{
    list<int> *adjacencyLists;
    Graph graph4 = Graph(12);
    graph4.addEdge(1, 2);
    graph4.addEdge(1, 3);
    graph4.addEdge(2, 3);
    graph4.addEdge(2, 4);
    graph4.addEdge(4, 5);
    graph4.addEdge(4, 6);
    graph4.addEdge(5, 7);
    graph4.addEdge(7, 6);
    graph4.addEdge(7, 10);
    graph4.addEdge(10, 8);
    graph4.addEdge(8, 9);
    graph4.addEdge(10, 11);
    graph4.addEdge(9, 11);
    graph4.addEdge(12, 11);
    CHECK(graph4.size() == 14);
    REQUIRE_NOTHROW(graph4.printBridges()); // 11,12 // 7,10 // 2,4
};

TEST_CASE("Creating a graph")
{
    list<int> *adjacencyLists;
    Graph graph1 = Graph(5);
    REQUIRE_NOTHROW(graph1.addEdge(1, 0));
    REQUIRE_NOTHROW(graph1.addEdge(0, 2));
    REQUIRE_NOTHROW(graph1.addEdge(2, 1));
    REQUIRE_NOTHROW(graph1.addEdge(0, 3));
    REQUIRE_NOTHROW(graph1.addEdge(3, 4));
};

TEST_CASE("Adding edges to a fully filled graph")
{
    list<int> *adjacencyLists;
    Graph graph1 = Graph(3);
    graph1.addEdge(1, 0);
    graph1.addEdge(0, 2);
    graph1.addEdge(2, 1);
    CHECK(graph1.size() == 3);
    REQUIRE_THROWS(graph1.addEdge(0, 3));
};
