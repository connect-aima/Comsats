#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
public:
    int V;        // number of vertices
    list<int> *l; // adjacency list

    Graph(int v) {
        V = v;
        l = new list<int>[V]; // create adjacency list for each vertex
    }

    void addEdges(int u, int v) { // undirected edge
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // BFS traversal with step-by-step print
    void bfs() {
        vector<bool> vis(V, false);
        queue<int> Q;
        vector<int> bfsOrder;

        Q.push(0); // start from node 0 (A)
        vis[0] = true;

        cout << "BFS Step-by-Step:\n";

        while (!Q.empty()) {
            int src = Q.front();
            Q.pop();
            bfsOrder.push_back(src);

            // Print current visited nodes
            cout << "Visited: ";
            for (int i = 0; i < V; i++)
                if (vis[i]) cout << char('A' + i) << " ";
            cout << "\n";

            // Print current queue
            cout << "Queue: ";
            queue<int> tmp = Q;
            while (!tmp.empty()) {
                cout << char('A' + tmp.front()) << " ";
                tmp.pop();
            }
            cout << "\n";

            cout << "Processing node: " << char('A' + src) << "\n\n";

            // Traverse neighbors
            for (int dest : l[src]) {
                if (!vis[dest]) {
                    vis[dest] = true;
                    Q.push(dest);
                }
            }
        }

        // Final BFS order
        cout << "Final BFS order: ";
        for (int node : bfsOrder) cout << char('A' + node) << " ";
        cout << "\n\n";
    }

    // DFS helper (recursive)
    void dfsHelper(int src, vector<bool> &vis, vector<int> &dfsOrder) {
        vis[src] = true;
        dfsOrder.push_back(src);

        // Print visited nodes at this step
        cout << "Visited: ";
        for (int i = 0; i < V; i++)
            if (vis[i]) cout << char('A' + i) << " ";
        cout << "\n";

        cout << "Processing node: " << char('A' + src) << "\n\n";

        for (int dest : l[src]) {
            if (!vis[dest])
                dfsHelper(dest, vis, dfsOrder);
        }
    }

    // DFS traversal
    void dfs() {
        vector<bool> vis(V, false);
        vector<int> dfsOrder;

        cout << "DFS Step-by-Step:\n";
        dfsHelper(0, vis, dfsOrder);

        // Final DFS order
        cout << "Final DFS order: ";
        for (int node : dfsOrder) cout << char('A' + node) << " ";
        cout << "\n\n";
    }
};

int main() {
    Graph g(5); // 5 intersections: A(0), B(1), C(2), D(3), E(4)

    // Add edges
    g.addEdges(0, 1); // A-B
    g.addEdges(0, 2); // A-C
    g.addEdges(1, 3); // B-D
    g.addEdges(2, 4); // C-E

    g.bfs(); // run BFS
    g.dfs(); // run DFS

    return 0;
}
