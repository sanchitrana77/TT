#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int tsp(vector<vector<int>>& graph, int src, vector<bool>& visited, int currPos, int n, int count, int cost, int& minCost) {
    if (count == n && graph[currPos][src] != 0) {
        minCost = min(minCost, cost + graph[currPos][src]);
        return minCost;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && graph[currPos][i] != 0) {
            visited[i] = true;
            tsp(graph, src, visited, i, n, count + 1, cost + graph[currPos][i], minCost);
            visited[i] = false;
        }
    }

    return minCost;
}

int travelingSalesman(vector<vector<int>>& graph, int src, int n) {
    vector<bool> visited(n, false);
    visited[src] = true;
    int minCost = INF;

    return tsp(graph, src, visited, src, n, 1, 0, minCost);
}

int main() {
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    // Input the adjacency matrix representing the graph
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix representing the graph:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int src = 0; // Starting city
    int minCost = travelingSalesman(graph, src, n);
    cout << "Minimum cost of the TSP: " << minCost << endl;

    return 0;
}
