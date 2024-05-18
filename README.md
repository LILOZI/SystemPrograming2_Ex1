# Graph Library - System Programing 2 Ex1
## Author
+ **Oz Atar**
+ **Email: ozfatar@gmail.com**
In this exercise I created a c++ library that has a Graph class and usefull
algorithms that you can use on it.

There are two main modules here:
+**Graph class**
+**Algorithms library**

Both modules and to be precise everything in this exercise is under the **GraphLib** namespace, under it there is the **Algorithms** namespace that covers the Algorithms that are in the API and more.

## Graph class
A class that represents an undirected/ directed unweighted/ weighted graph.
### Graph's user manual

+**Creating a graph** - To create a graph you need to create a refrence using the defult constuctor, afterward you load values to it using the **loadGraph** method with a two dimensional vector of integers, more on loadGraph later.

+**Modifying the graph?** - After loading the graph you can not change the values of a certain edge or add another vertex, you need to override the previous graph with another loadGraph assignment.

+**Information about initialized graph** - After loading a graph you can gain information about it using the following methods:
    +**isDirected** - Whether the loaded graph is directed or not.
    +**isWeighted** - Whether the loaded graph is weighted or not.
    +**isNegValues** - Whether the loaded graph has negative edge values or not.
One can also use **isLoaded** to know whether a graph was loaded or not.

+**Print** - One can print a short message describing the graph using the **printGraph** method.

### Graph's methods

+**loadGraph** - This function receives a two dimensional vector of integers and assigns the values to the matrix that represent the graph, the given two dimensional vector must be squared.
At this stage information about the graph is also gathered.

+**getNumVertices** - Return the amout of vertices in the graph.
+**getWeight** - Given to positive integers the function will return the weight of the edge between them.

To see more of the Graph functions and understand further the implementation be sure to check the [Graph.hpp](https://github.com/LILOZI/SystemPrograming2_Ex1/blob/main/Graph.hpp) and [Graph.cpp](https://github.com/LILOZI/SystemPrograming2_Ex1/blob/main/Graph.cpp) which are thoroughly documented.

## Algoriths
Set of function that you can use on any graph implemention that supports a certain interface.

### Algorithms and their description

+**isConnected** - Whether a given Graph is connected or not.

+**shortestPath** - Given two positive integers that represent the graph vertices and 
the graph itself it return the shortest path between them if exsists.

+**isContainsCycle** - Returns an unweighted cycle inside the graph if one exsists.

+**isBipartite** - Given a graph return whether the graph is bipartite or not and the partition itself.

+**negativeCycle** - Given a graph return whether there is a negative weight cycle in the graph and returns it.

To see more on the Algorithms and understand further the implementation be sure to check the [Algorithms.hpp](https://github.com/LILOZI/SystemPrograming2_Ex1/blob/main/Algorithms.hpp) and [Algorithms.cpp](https://github.com/LILOZI/SystemPrograming2_Ex1/blob/main/Algorithms.cpp) files which are thoroughly documented.

When implementing the algorithms I used other algorithms to help me, I did not include them here to apply the principle of minimal API, however you can check their description at the HelpAlgo.hpp file or their implementation at the Algorithms.cpp file.







