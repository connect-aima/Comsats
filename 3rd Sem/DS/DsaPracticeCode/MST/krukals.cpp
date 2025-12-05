#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;

    return parent[u] = findParent(parent[u], parent); // path compression
}
void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    // if both have same parents it means they are already in same sets so return
    if (pu == pv)
        return;
    // merger smaller in bigger
    // if rank of parent of u is greater than rank of parent of v then merger v with parent of u
    if (rank[pu] > rank[pv])
    {
        parent[pv] = pu; // attach v's root to u's root
    }
    else if (rank[pv] > rank[pu])
    {                    // if rank of parent of v is greater than rank of parent of u then merger u with parent of v
        parent[pu] = pv; // attach u's root to v's root
    }
    else
    {
        parent[pu] = pv; // if both parents are on same rank then merger with your choic i am merging u under v
        rank[pv]++;      // increse rank of v
    }
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);  // intialized parent array of size of total vertices
    vector<int> rank(V, 0); // intialized rank array of size of total vertices with initially 0 at all indexes
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // prioroty queue
    // weight,u,v
    using Edge = pair<int, pair<int, int>>; // (weight, (u,v))
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
//in below loop i is basically u 
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j][0];  // neighbor vertex
            int wt = adj[i][j][1]; // weight of edge i-v
            if (i < v)             // push only once for undirected graph
                pq.push({wt, {i, v}});
        }
    }

    int cost = 0;
    int edges = 0;
    while (!pq.empty() && edges < V - 1)
    {
        int weight = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if (findParent(u, parent) != findParent(v, parent))
        {
            cost += weight;
            unionByRank(u, v, parent, rank);
            edges++; // increment edges included in MST
        }
    }

    return cost;
}

int main()
{

    return 0;
}