//
// Created by Ankit Sahu on 9/30/24.
//
/*
 * The time complexity of this implementation is
O(ElogV), where
E is the number of edges and
V is the number of vertices
*/

// Include the header file for building the graph
#include "/Users/sahuankit010/Desktop/Repo/DSA-End-to-End/Graph/BuildGraph.h"
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// Class implementing Dijkstra's algorithm
class Dijkstra {
public:
    BuildGraph obj;  // Object to build and retrieve the graph

    // Function to perform Dijkstra's algorithm
    void dijkstraAlgo() {

        // Retrieve the adjacency list of the graph
        // The graph is represented as an unordered_map where:
        // Key: node identifier (int)
        // Value: vector of pairs (neighbor node, edge weight)
        unordered_map<int, unordered_map<int, int>  > adj; adj = obj.getGraph();

        // Get the number of nodes in the graph
        int size = adj.size();

        cout << "Number of nodes in the graph: " << size << "\n";

        // Initialize distances to all nodes as infinite (INT_MAX)
        vector<int> distance(size, INT_MAX);

        // Min-heap priority queue to select the node with the smallest distance
        // The queue stores pairs of (distance to node, node identifier)
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        // Assume the source node is node 0
        distance[0] = 0;  // Distance from source to itself is 0
        pq.push(make_pair(0, 0));  // Push the source node into the priority queue

        // Loop until the priority queue is empty
        while (!pq.empty()) {

            // Extract the node with the smallest distance from the priority queue
            int node = pq.top().second;  // Current node
            int dis = pq.top().first;    // Distance to current node
            pq.pop();  // Remove the node from the queue

            // Iterate over all adjacent nodes (neighbors) of the current node
            for (auto &neighbor : adj[node]) {
                int v = neighbor.first;       // Neighbor node identifier
                int weight = neighbor.second; // Edge weight between current node and neighbor

                // Relaxation step: update the distance if a shorter path is found
                if (distance[v] > dis + weight) {
                    distance[v] = dis + weight;          // Update distance to neighbor
                    pq.push(make_pair(distance[v], v));  // Push the updated neighbor into the queue
                }
            }
        }

        // Print the shortest distances from the source to all other nodes
        printf("Vertex \t Distance from Source\n");
        for (int i = 0; i < size; i++) {
            if (distance[i] == INT_MAX) {
                printf("%d \t\t %s\n", i, "INF");  // If unreachable, print INF
            } else {
                printf("%d \t\t %d\n", i, distance[i]);  // Print the distance
            }
        }
    }
};

int main() {

    Dijkstra dijkstra;      // Create an instance of the Dijkstra class
    dijkstra.dijkstraAlgo();  // Call the Dijkstra algorithm function to compute shortest paths
    return 0;
}
