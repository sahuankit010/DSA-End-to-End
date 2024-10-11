//
// Created by Ankit Sahu on 9/30/24.
// https://leetcode.com/problems/maximum-number-of-accepted-invitations/
//

#include "FordFulkerson.h"

#include<iostream>
#include<vector>
#include<queue>

using namespace  std;

class FordFulkerson {
public:
    int m, n;
    int totalNodes;
    int source;
    int sink;

    bool bfs(vector<vector<int> > &residualGraph, vector<int> &parent){
        queue<int> q;
        vector<int> visited(totalNodes, 0);
        q.push(source);
        parent[source] = -1;
        visited[source] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v = 0; v<totalNodes; v++){
                if(visited[v] == 0 && residualGraph[u][v] > 0){
                    visited[v] = 1;
                    q.push(v);
                    parent[v] = u;
                    if(v == sink) return true;
                }
            }
        }

        return false;
    }

    int fordFulkerson(vector<vector<int> >&grid){
        m = grid.size();
        n = grid[0].size();

        totalNodes = m+n+2;
        source = 0;
        sink   = m+n-1;
        //rows represent boys and cols represent girls
        vector<vector<int> > residualGraph(totalNodes, vector<int> (totalNodes));

        // Step 1: Connect the source node to all boy nodes
        // Boys are assigned indices from 1 to m
        for(int i=0; i<m; i++){
            residualGraph[source][i+1] = 1;
        }

        // Step 2: Connect boy nodes to girl nodes based on the grid
        // Girls are assigned indices from m + 1 to m + n
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    residualGraph[i+1][m+1+j] = 1;
                }
            }
        }

        for(int i=0; i<n; i++){
            residualGraph[m+1+i][sink] = 1;
        }

        int maxFlow = 0;
        vector<int>parent(totalNodes, -1);

        while(bfs(residualGraph, parent)){

            int pathFlow = 1;

            for(int v = sink; v != source; v = parent[v]){
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }
};

int main(){
    cout<<"Main\n";
    FordFulkerson fordFulkerson;
    std::vector<std::vector<int> > grid;


    grid.push_back({1, 1, 1});
    grid.push_back({1, 0, 1});
    grid.push_back({0, 0, 1});

    int ans =  fordFulkerson.fordFulkerson(grid);

    cout<<ans;
}