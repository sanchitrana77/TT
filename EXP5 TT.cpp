#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight;
    
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    if (e1.weight == e2.weight) {
        return e1.from + e1.to + e1.weight < e2.from + e2.to + e2.weight;
    }
    return e1.weight < e2.weight;
}

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<Edge> edges;
    for (int i = 0; i < g_from.size(); ++i) {
        edges.push_back(Edge(g_from[i], g_to[i], g_weight[i]));
    }
    
    sort(edges.begin(), edges.end(), compareEdges);
    
    DisjointSet ds(g_nodes + 1);
    
    int totalWeight = 0;
    for (const auto& edge : edges) {
        if (ds.find(edge.from) != ds.find(edge.to)) {
            totalWeight += edge.weight;
            ds.unite(edge.from, edge.to);
        }
    }
    
    return totalWeight;
}

int main() {
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    vector<int> g_from(g_edges), g_to(g_edges), g_weight(g_edges);
    for (int i = 0; i < g_edges; ++i) {
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
    }

    int result = kruskals(g_nodes, g_from, g_to, g_weight);
    cout << result << endl;

    return 0;
}
