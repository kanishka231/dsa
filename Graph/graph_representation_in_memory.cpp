// 1. Objects and Pointers Representation
// This representation uses classes or structs where each node (vertex) is an object, 
// and edges are represented as pointers (or references) to other nodes.


#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
// Define a class for a node (vertex)
class Node {
public:
    int value;
    list<Node*> neighbors;
    Node(int value) {
        this->value = value;
    }

    void addNeighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }
};

// Define a class for a graph
class Graph {
public:
    vector<Node*> nodes;
    Graph() {}

    void addNode(Node* node) {
        nodes.push_back(node);
    }
};

int main() {
    // Create a graph
    Graph* graph = new Graph();

    // Create nodes
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // Add nodes to the graph
    graph->addNode(node1);
    graph->addNode(node2);
    graph->addNode(node3);
    graph->addNode(node4);

    // Add edges
    node1->addNeighbor(node2);
    node1->addNeighbor(node3);
    node2->addNeighbor(node4);
    node3->addNeighbor(node4);

    // Print the graph
    for (Node* node : graph->nodes) {
        cout << "Node " << node->value << " is connected to: ";
        for (Node* neighbor : node->neighbors) {
            cout << neighbor->value << " ";
        }
        cout << endl;
    }

    return 0;
}


// Pros:
// Flexible and easy to extend with additional data (like weights or properties).
// Well-suited for object-oriented programming.
// Cons:
// Memory overhead due to pointers.
// Complex traversal compared to adjacency matrix or list.
// Inefficient for dense graphs.


// 2. Adjacency List Representation
// This representation uses an array of lists to store the neighbors of each node.
// The index of the array represents the node, and the list at that index contains the neighbors of that node.
// This representation is more memory-efficient than the adjacency matrix representation for sparse graphs.
// However, it can be slower for dense graphs because it requires more memory accesses to traverse the graph
// (because we need to access the list of neighbors for each node, rather than just accessing a
// single row or column in the adjacency matrix).
//
// Example code in C++:
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices = 3; // Number of vertices
    vector<vector<int>> adjList(vertices);

    // Adding edges
    adjList[0].push_back(1); // Edge from 0 to 1
    adjList[1].push_back(2); // Edge from 1 to 2
    adjList[2].push_back(0); // Edge from 2 to 0

    // Displaying the adjacency list
    for (int i = 0; i < adjList.size(); i++) {
        cout << "Vertex " << i << " is connected to: ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
// Pros:
// Memory-efficient for sparse graphs (𝑂(𝑉+𝐸) O(V+E)).
// Easy to traverse neighbors of a vertex.
// Suitable for dynamic graphs.
// Cons:
// Edge existence checks are slower (𝑂(𝑉)
// O(V) in the worst case for a vertex).
// Less efficient for dense graphs.


// 3. Adjacency Matrix Representation
// This representation uses a 2D array to store the presence or absence of edges between nodes.
// The value at index (i, j) in the matrix represents the edge between node i and node j.
// This representation is memory-efficient for dense graphs, as it only requires 𝑉^2 memory
// O(V^2) memory, regardless of the number of edges.
// However, it can be inefficient for sparse graphs, as it may waste memory storing many zeros.
//
// Example code in C++:
#include <iostream>
#include <vector>
using namespace std;
// Adjacency Matrix Representation
int main() {
    int vertices = 3; // Number of vertices
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
    // Initialize the adjacency matrix with zeros.
    // Adding edges
    adjMatrix[0][1] = 1; // Edge from 0 to 1
    adjMatrix[1][2] = 1; // Edge from 1 to 2
    adjMatrix[2][0] = 1; // Edge from 2 to 0
    // Displaying the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// Pros:
// Memory-efficient for dense graphs (𝑂(𝑉^2) O(V^2)).
// Fast edge existence checks (𝑂(1) O(1))
// Suitable for dense graphs.
// Cons:
// Inefficient for sparse graphs.
// Requires 𝑉^2 memory (O(V^2)) regardless of the number of edges.
// Not suitable for dynamic graphs (changing the number of vertices or edges).


// 4. Adjacency Map Representation
// An adjacency map uses a hash map (or dictionary) where each vertex maps to another map, often used for weighted graphs.
// The inner map contains the neighbors of the vertex as keys and the edge weights as values.
// This representation is memory-efficient for sparse graphs and allows for fast edge weight lookups.
// However, it may have slower edge existence checks compared to the adjacency list representation.

// Example code in C++:
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// Adjacency Map Representation
int main() {
    int vertices = 3; // Number of vertices
    unordered_map<int, unordered_map<int, int>> adjMap;
    // Adding edges
    adjMap[0][1] = 1; // Edge from 0 to 1 with weight 1
    adjMap[1][2] = 2; // Edge from 1 to 2 with weight 2
    adjMap[2][0] = 3; // Edge from 2 to 0 with weight 3
    // Displaying the adjacency map
    for (auto& entry : adjMap) {
        int vertex = entry.first;
        cout << "Vertex " << vertex << " is connected to: ";
        for (auto& neighbor : entry.second) {
            cout << neighbor.first << " (weight: " << neighbor.second << ") ";
        }
        cout << endl;
    }
    return 0;
}

  
