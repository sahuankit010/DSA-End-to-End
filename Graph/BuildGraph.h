//
// Created by Ankit Sahu on 9/29/24.
//

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class BuildGraph {
public:
    unordered_map<int, vector<pair<int, int> > > adj;

    unordered_map<int, vector<pair<int, int> > > getGraph() {
        return adj;
    }
    void addEdge(unordered_map<int, vector<pair<int, int> > > &adj, int u, int v, int wt) {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }


    void printGraph() {
        for (auto it: adj) {
            cout << it.first << endl;
            for (int i = 0; i < it.second.size(); i++) {
                cout << it.second[i].first << " " << it.second[i].second << endl;
            }
        }
    }

    BuildGraph() {
        addEdge(adj, 0, 1, 4);
        addEdge(adj, 0, 7, 8);
        addEdge(adj, 1, 2, 8);
        addEdge(adj, 1, 7, 11);
        addEdge(adj, 2, 3, 7);
        addEdge(adj, 2, 8, 2);
        addEdge(adj, 2, 5, 4);
        addEdge(adj, 3, 4, 9);
        addEdge(adj, 3, 5, 14);
        addEdge(adj, 4, 5, 10);
        addEdge(adj, 5, 6, 2);
        addEdge(adj, 6, 7, 1);
        addEdge(adj, 6, 8, 6);
        addEdge(adj, 7, 8, 7);
        printGraph();
    }
};

