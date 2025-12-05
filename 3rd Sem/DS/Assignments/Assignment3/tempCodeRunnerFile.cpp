#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    char u, v;
    int weight;
};

// Structure for Union-Find (Disjoint Set)
struct DisjointSet {
    char parent[100];

    // Initialize each node as its own parent
    void makeSet(vector<char> nodes) {
        for (char c : nodes)
            parent[c] = c;
    }

    // Find representative (root) of a set
    char find(char x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    // Union two sets
    void unite(char x, char y) {
        parent[find(x)] = find(y);
    }
};

// Compare edges by weight
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    // Create the graph (edge list)
    vector<Edge> edges = {
        {'A', 'C', 15},
        {'B', 'C', 20},
        {'B', 'D', 25},
        {'C', 'E', 30},
        {'D', 'E', 35},
        {'E', 'F', 40},
        {'E', 'G', 45},
        {'F', 'G', 50}
    };

    // List of unique nodes
    vector<char> nodes = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Create disjoint set
    DisjointSet ds;
    ds.makeSet(nodes);

    cout << "Edges sorted by weight:\n";
    for (auto &e : edges)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;

    cout << "\nKruskal's Algorithm Process:\n";
    
    vector<Edge> mst;  // store MST edges
    int totalCost = 0;

    for (auto &e : edges) {
        char setU = ds.find(e.u);
        char setV = ds.find(e.v);

        if (setU != setV) {
            // Accept the edge
            mst.push_back(e);
            totalCost += e.weight;
            ds.unite(e.u, e.v);
            cout << "ACCEPT: " << e.u << " - " << e.v << " (" << e.weight << ")\n";
        } else {
            // Reject edge
            cout << "REJECT: " << e.u << " - " << e.v << " (" << e.weight << ") - forms cycle\n";
        }
    }

    cout << "\nFinal MST Edges:\n";
    for (auto &e : mst)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;

    cout << "\nTotal MST Distance = " << totalCost << " miles\n";

    return 0;
}
