#include <vector>
#include <iostream>
#include <stdexcept>
#pragma once

namespace GraphLib{
    #define INT_MAX 2147483647
    #define NO_EDGE 0
    enum Color{WHITE, GRAY, BLACK};

    /**
     * @class Graph
     * @brief This class represents a graph.
     * @brief The graph can be directed or undirected, weighted or unweighted.
     * @brief The graph can contain negative values or not.
     * @brief The graph uses an adjacency matrix to represent the graph, hence 
     * @brief the graph is loaded by squared matrices only. 
     * @brief The graph can not have an edge weighted as 0, the value 0 is used to represent no edge.
     **/
    class Graph {
        private:
        std::vector<std::vector<int>> adjTable;
        bool directed;
        bool weighted;
        bool negValues;
        bool loaded;
        bool isSymetric();
        void setDirected() {directed = true;}
        void setWeighted() {weighted = true;}
        void setNegValues() {negValues = true;}
        void setLoaded() {loaded = true;}
        void clear() {adjTable.clear();loaded = false; directed = false; weighted = false; negValues = false;}
        public:
        Graph();

        ~Graph();
        
        /**
         * @return The number of vertices in the graph.
         * @throws std::invalid_argument if the graph is not loaded.
        **/
        size_t getNumVertices() const {
            if(!loaded){throw std::invalid_argument("The graph is not loaded.");}
            return adjTable.size();
        }

        /**
         * @param i The vertex that the edge "lefts".
         * @param j The vertex that the edge "enters".
         * @return The weight of the edge between the two vertices.
         * @throws std::invalid_argument if the given vertices are out of range or the graph is not loaded.
        **/
        int getWeight(size_t i, size_t j) const {
            if(i >= adjTable.size() || j >= adjTable.size()){throw std::invalid_argument("The given vertices are out of range.");}
            if(!loaded){throw std::invalid_argument("The graph is not loaded.");}
            return adjTable[i][j];
        }

        /**
         * @brief This method loads values to the adjacency matrix that represents the graph.
         * @param mat The matrix that represents the graph.
         * @return true if the graph is loaded, false otherwise.
         * @throws std::invalid_argument if the given matrix is not squared or empty.
        **/
        void loadGraph(std::vector<std::vector<int>> mat);
        /**
         * @brief This method prints information about the graph in the following format:
         * @brief "This is {a directed/ an undirected} graph with {number of vertices} vertices and {number of edges} edges."
         * @throws std::invalid_argument if the graph is not loaded.
        **/
        void printGraph();

        /**
         * @return Whether the graph is directed or not.
        **/
        bool isDirected() const {return directed;}

        void setUnDirected() {directed = false;}

        /**
         * @return Whether the graph is weighted or not.
        **/
        bool isWeighted() const {return weighted;}

        /**
         * @return Whether the graph has negative values or not.
        **/
        bool isNegValues() const {return negValues;}

        /**
         * @return Whether the graph has been loaded or not.
        **/
       bool isLoaded() const {return loaded;}

        /**
         * @return The adjacency matrix that represents the graph.
        **/
        std::vector<std::vector<int>> getGraph() const {return adjTable;}

    };
};