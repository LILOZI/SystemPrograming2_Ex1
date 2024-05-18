/**
 * @author Oz Atar
 * mail: ozfatar@gmail.com
**/

#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

TEST_CASE("Test isConnected undirected graph"){

    GraphLib::Graph g;
    
    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, 1, NO_EDGE, NO_EDGE},
        {1, NO_EDGE, 1, NO_EDGE},
        {NO_EDGE, 1, NO_EDGE, 1},
        {NO_EDGE, NO_EDGE, 1, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::isConnected(g) == "The graph is connected.");

    std::vector<std::vector<int>> graph2 = {
        {NO_EDGE, 5, -2, NO_EDGE},
        {5, NO_EDGE, NO_EDGE, -11},
        {-2, NO_EDGE, NO_EDGE, 19},
        {NO_EDGE, -11, 19, NO_EDGE}
    };
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::isConnected(g) == "The graph is connected.");

    std::vector<std::vector<int>> graph3 = {
        {NO_EDGE, 1, NO_EDGE, NO_EDGE},
        {1, NO_EDGE, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, 1},
        {NO_EDGE, NO_EDGE, 1, NO_EDGE}
    };
    g.loadGraph(graph3);
    CHECK(GraphLib::Algorithms::isConnected(g) == "The graph is not connected.");

    std::vector<std::vector<int>> graph4 = {
        {NO_EDGE, -12, NO_EDGE, NO_EDGE, 17},
        {-12, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, 3, NO_EDGE},
        {NO_EDGE, NO_EDGE, 3, NO_EDGE, NO_EDGE},
        {17, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph4);
    CHECK(GraphLib::Algorithms::isConnected(g) == "The graph is not connected.");
}

TEST_CASE("Test isConnected directed graph"){

    GraphLib::Graph g;

    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, 1, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, 1, NO_EDGE},
        {1, 1, NO_EDGE, 1},
        {NO_EDGE, 1, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::isConnected(g) == "The graph is connected.");

    std::vector<std::vector<int>> graph2 = {
        {NO_EDGE, 5, -2, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, -11},
        {12, 2, NO_EDGE, 19},
        {NO_EDGE, 7, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::isConnected(g) == "The graph is connected.");

    std::vector<std::vector<int>> graph3 = {
        {NO_EDGE, 11, -12, 5, NO_EDGE, NO_EDGE}, 
        {NO_EDGE, NO_EDGE, 7, NO_EDGE, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE}, 
        {NO_EDGE, 3, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
        {NO_EDGE, 1, NO_EDGE, NO_EDGE, NO_EDGE, 5},
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE}

    };
    g.loadGraph(graph3);
    CHECK(GraphLib::Algorithms::isConnected(g) == "The graph is not connected.");
}

TEST_CASE("Test shortest path using BFS"){
    
    GraphLib::Graph g;

    std::vector<std::vector<int>> graph1 {
        {NO_EDGE, 1, NO_EDGE, NO_EDGE},
        {1, NO_EDGE, 1, NO_EDGE},
        {NO_EDGE, 1, NO_EDGE, 1},
        {NO_EDGE, NO_EDGE, 1, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 3) == "The shortest path is: 0->1->2->3");
    
    std::vector<std::vector<int>> graph2 = {
        {NO_EDGE, 1, NO_EDGE, NO_EDGE},
        {1, NO_EDGE, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, 1},
        {NO_EDGE, NO_EDGE, 1, NO_EDGE}
    };
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 2) == "There is no path between 0 and 2.");
}

TEST_CASE("Test shortest path using Dijkstra"){

    GraphLib::Graph g;

    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, 6, 30, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
        {6, NO_EDGE, 12, 2, 1, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
        {10, 3, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 8, 16, NO_EDGE, NO_EDGE},
        {NO_EDGE, 11, 12, NO_EDGE, NO_EDGE, 6, 3, 1, NO_EDGE, NO_EDGE},
        {NO_EDGE, 14, NO_EDGE, NO_EDGE, NO_EDGE, 4, 3, NO_EDGE, 6, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, 6, 4, NO_EDGE, NO_EDGE, NO_EDGE, 12, NO_EDGE},
        {NO_EDGE, 5, 8, 3, NO_EDGE, NO_EDGE, NO_EDGE, 2, 16, 6},
        {NO_EDGE, NO_EDGE, 3, NO_EDGE, 2, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 8},
        {NO_EDGE, NO_EDGE, 5, NO_EDGE, 6, 12, NO_EDGE, NO_EDGE, NO_EDGE, 13},
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 6, 8, NO_EDGE, NO_EDGE}};
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 5) == "The shortest path is: 0->1->4->5");
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 8) == "The shortest path is: 0->1->4->8");
    CHECK(GraphLib::Algorithms::shortestPath(g, 1, 6) == "The shortest path is: 1->4->6");
    CHECK(GraphLib::Algorithms::shortestPath(g, 7, 1) == "The shortest path is: 7->2->1");

    std::vector<std::vector<int>> graph2 = {
        {NO_EDGE, 12, 5, NO_EDGE, 1, NO_EDGE},
        {12, NO_EDGE, NO_EDGE, 3, NO_EDGE, 15},
        {5, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
        {NO_EDGE, 3, NO_EDGE, NO_EDGE, NO_EDGE, 5},
        {1, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
        {NO_EDGE, 15, NO_EDGE, 5, NO_EDGE, NO_EDGE}};
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 5) == "The shortest path is: 0->1->3->5");
    CHECK(GraphLib::Algorithms::shortestPath(g, 3, 2) == "The shortest path is: 3->1->0->2");
}

TEST_CASE("Test shortest path using Bellman-Ford"){
    GraphLib::Graph g;

    std::vector<std::vector<int>> graph = {
        {NO_EDGE, -1, NO_EDGE},
        {1, NO_EDGE, -5},
        {NO_EDGE, NO_EDGE, NO_EDGE}
    };

    g.loadGraph(graph);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 1) == "The shortest path is: 0->1");
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 2) == "The shortest path is: 0->1->2");
    CHECK(GraphLib::Algorithms::shortestPath(g, 1, 2) == "The shortest path is: 1->2");
    CHECK(GraphLib::Algorithms::shortestPath(g, 2, 0) == "There is no path between 2 and 0.");
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 0) == "The shortest path is: 0");

    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, -135, -32, NO_EDGE, NO_EDGE}, 
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE}, 
        {NO_EDGE, NO_EDGE, NO_EDGE, -39, NO_EDGE}, 
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, -70}, 
        {NO_EDGE, -21, NO_EDGE, NO_EDGE, NO_EDGE}
    };

    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 1) == "The shortest path is: 0->2->3->4->1");

    graph1[0][1] = -1000;
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 1) == "The shortest path is: 0->1");

    std::vector<std::vector<int>> graph2 = {
        {NO_EDGE, NO_EDGE, NO_EDGE, 2, -2}, 
        {NO_EDGE, NO_EDGE, -1, NO_EDGE, NO_EDGE}, 
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE}, 
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, -8}, 
        {NO_EDGE, NO_EDGE, 2, NO_EDGE, NO_EDGE}
    };

    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 2) == "The shortest path is: 0->3->4->2");  

    std::vector<std::vector<int>> graph3 = {
        {NO_EDGE, -1, NO_EDGE},
        {NO_EDGE, NO_EDGE, -1},
        {1, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph3);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 1) == "0 and 1 are connected by a negative weight cycle.");

    std::vector<std::vector<int>> graph4 = {
    { NO_EDGE, 5, 3, NO_EDGE, NO_EDGE},
    { NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
    { NO_EDGE, NO_EDGE, NO_EDGE, -2, NO_EDGE}, 
    { NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, -1}, 
    { NO_EDGE, NO_EDGE, -1, NO_EDGE, NO_EDGE} 
    };
    g.loadGraph(graph4);
    CHECK(GraphLib::Algorithms::shortestPath(g, 0, 1) == "The shortest path is: 0->1");
}

TEST_CASE("Test shortest path input"){

    GraphLib::Graph g;
    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, 1, NO_EDGE, NO_EDGE},
        {1, NO_EDGE, 1, NO_EDGE},
        {NO_EDGE, 1, NO_EDGE, 1},
        {NO_EDGE, NO_EDGE, 1, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK_THROWS_AS(GraphLib::Algorithms::shortestPath(g, 0, 4), std::invalid_argument);
}

TEST_CASE("Test isContainsCycle undirected graph"){

    GraphLib::Graph g;

    std::vector<std::vector<int>> graph1= {
        {NO_EDGE, 1, 1},
        {1, NO_EDGE, 1},
        {1, 1, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");

    std::vector<std::vector<int>> graph2 = {
    {NO_EDGE, 1, NO_EDGE, NO_EDGE},
    {1, NO_EDGE, 1, 1},
    {NO_EDGE, 1, NO_EDGE, 1},
    {NO_EDGE, 1, 1, NO_EDGE}
    };
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::isContainsCycle(g) == "The cycle is: 1->2->3->1");

    std::vector<std::vector<int>> graph3 = {
        {NO_EDGE, 5, 13},
        {5, NO_EDGE, NO_EDGE},
        {13, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph3);
    CHECK(GraphLib::Algorithms::isContainsCycle(g) == "There is no cycle in the graph.");
}

TEST_CASE("Test isContainsCycle directed graph"){
    
    GraphLib::Graph g;
    
    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, 12, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, -17, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, -100},
        {NO_EDGE, 35, NO_EDGE, NO_EDGE}
    };

    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::isContainsCycle(g) == "The cycle is: 1->2->3->1");

    std::vector<std::vector<int>> graph2 = {
        {NO_EDGE, 1, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, 1, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, 1},
        {1, NO_EDGE, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->3->0");

    std::vector<std::vector<int>> graph3 = {
        {NO_EDGE, 5, 13},
        {NO_EDGE, NO_EDGE, 3},
        {NO_EDGE, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph3);
    CHECK(GraphLib::Algorithms::isContainsCycle(g) == "There is no cycle in the graph.");
     
    std::vector<std::vector<int>> graph4 = {
        {NO_EDGE, 5, 13},
        {NO_EDGE, NO_EDGE, NO_EDGE},
        {-7, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph4);
    CHECK(GraphLib::Algorithms::isContainsCycle(g) == "The cycle is: 0->2->0");
}

TEST_CASE("Test isBipartite"){
    // no need to check directed / undirected because the algorithm 
    // turns directed graph to an undirected one
    GraphLib::Graph g;
    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, 1, NO_EDGE, 1},
        {-13, NO_EDGE, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE,7},
        {1 , NO_EDGE, 12, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}.");

    std::vector<std::vector<int>> graph2 = {
        {NO_EDGE, -1, NO_EDGE, NO_EDGE, NO_EDGE},
        {1, NO_EDGE, 2, NO_EDGE, NO_EDGE},
        {NO_EDGE, 3, NO_EDGE, 4, NO_EDGE},
        {NO_EDGE, NO_EDGE, -9, NO_EDGE, 7},
        {NO_EDGE, NO_EDGE, NO_EDGE, 5, NO_EDGE}};
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}.");

    std::vector<std::vector<int>> graph3 = {
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
        {4, NO_EDGE, -6, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE, 5},
        {NO_EDGE, -2, NO_EDGE, NO_EDGE}};
    g.loadGraph(graph3);
    CHECK(GraphLib::Algorithms::isBipartite(g) == "The graph is not bipartite.");
}

TEST_CASE("Test negativeCycle undirected graph"){

    GraphLib::Graph g;
    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, -11, NO_EDGE},
        {-11, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::negativeCycle(g) == "The graph has no negative cycle.");

    std::vector<std::vector<int>> graph2 = {
    {NO_EDGE, 7, 5, NO_EDGE, NO_EDGE}, 
    {7, NO_EDGE, NO_EDGE, NO_EDGE, 5}, 
    {5, NO_EDGE, NO_EDGE, -17 , NO_EDGE},
    {NO_EDGE, NO_EDGE, -17, NO_EDGE, -1},
    {NO_EDGE, 5, NO_EDGE, -1, NO_EDGE}  
    };
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::negativeCycle(g) == "The negative cycle is: 0->2->3->4->1->0");

    std::vector<std::vector<int>> graph3= {
        {NO_EDGE, 19, -7},
        {19, NO_EDGE, -3},
        {-7, -3, NO_EDGE}};
    g.loadGraph(graph3);
    CHECK(GraphLib::Algorithms::negativeCycle(g) == "The graph has no negative cycle.");
}

TEST_CASE("Test negativeCycle directed graph"){
    GraphLib::Graph g;
    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, -11, NO_EDGE},
        {-15, NO_EDGE, NO_EDGE},
        {NO_EDGE, NO_EDGE, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK(GraphLib::Algorithms::negativeCycle(g) == "The negative cycle is: 0->1->0");

    std::vector<std::vector<int>> graph2 = {
    {NO_EDGE, 7, 5, NO_EDGE, NO_EDGE}, 
    {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE}, 
    {NO_EDGE, 2, NO_EDGE, -17 , NO_EDGE},
    {4, NO_EDGE, NO_EDGE, NO_EDGE, -1},
    {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE}  
    };
    g.loadGraph(graph2);
    CHECK(GraphLib::Algorithms::negativeCycle(g) == "The negative cycle is: 0->2->3->0");

    std::vector<std::vector<int>> graph3 = {
        {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
        {5, NO_EDGE, -9, NO_EDGE},
        {2, NO_EDGE, NO_EDGE, 2},
        {NO_EDGE, -3, NO_EDGE, NO_EDGE}};
    g.loadGraph(graph3);
    CHECK(GraphLib::Algorithms::negativeCycle(g) == "The negative cycle is: 1->2->3->1");

    
}

TEST_CASE("Test empty graphs"){
    
    GraphLib::Graph g;
    
    CHECK_THROWS_AS(GraphLib::Algorithms::isConnected(g), std::invalid_argument);
    CHECK_THROWS_AS(GraphLib::Algorithms::shortestPath(g, 0, 1), std::invalid_argument);
    CHECK_THROWS_AS(GraphLib::Algorithms::isContainsCycle(g), std::invalid_argument);
    CHECK_THROWS_AS(GraphLib::Algorithms::isBipartite(g), std::invalid_argument);
    CHECK_THROWS_AS(GraphLib::Algorithms::negativeCycle(g), std::invalid_argument);
}

TEST_CASE("Graph functions"){

    GraphLib::Graph g;
    
    CHECK(g.isLoaded() == false);
    CHECK_THROWS_AS(g.getNumVertices(), std::invalid_argument);
    CHECK_THROWS_AS(g.printGraph(), std::invalid_argument);
    CHECK_THROWS_AS(g.getWeight(0, 3), std::invalid_argument);
    
    std::vector<std::vector<int>> graph1 = {
        {NO_EDGE, 5, NO_EDGE, NO_EDGE},
        {1, NO_EDGE, 1, NO_EDGE},
        {NO_EDGE, -3, NO_EDGE, 1},
        {NO_EDGE, NO_EDGE, 1, NO_EDGE}
    };
    g.loadGraph(graph1);
    CHECK(g.isLoaded() == true);
    CHECK(g.isDirected() == true);
    CHECK(g.getNumVertices() == 4);
    CHECK(g.getWeight(0, 1) == 5);
    CHECK_THROWS_AS(g.getWeight(0, 4), std::invalid_argument);
}