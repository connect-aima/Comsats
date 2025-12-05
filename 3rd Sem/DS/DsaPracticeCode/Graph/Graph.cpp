#include <iostream>
// we use STL dynamic list to build graph which is internally doubly linked list(dynamic array)
#include <list>
//including queue for traversals
#include <queue>
using namespace std;
class Graph
{
public:
    int V;        // deefined number of verteces
    list<int> *l; // list of integer at each vertex(int* arr)


    Graph(int v)
    {
        V = v;
        l = new list<int>[V]; // arr=new int [V]
    }
    // below two parameter are nodes of two edges respectively
    // 1-3=>we will assume it as u and v . as it is undirected graph we will add 3 in neighbours
    //  in neighbors of 1 and 1 in neighbour of 3
    void addEdges(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
        
    }
// //simply printing graph
//     void printGraph(){
//         for(int i=0;i<V;i++){
//             cout << i << " : ";
//             for(int neighbour : l[i]){
//                 cout << neighbour << " " ;
//             }
//             cout << endl;
//         }
//     }
    //traversals
    // BFS travel to immediate neighbours first
    void bfs(){//yime comlpexity(V+E)
        //intiate queue of integer type
        queue<int> Q;
        vector <bool> vis(V,false);
        Q.push(0);
        vis[0]=true;
        while(Q.size()>0){
            int src=Q.front();
            Q.pop();
            cout << src << " " ;
            for(int destination:l[src]){
                if(!vis[destination]){
                    vis[destination]=true;
                    Q.push(destination);
                }
            }
        }
    }
    //keep going to first un visited neighbour first
    void dfsHelper(int src,vector<bool> &vis){//O(V+E)
        cout << src << " ";
        vis[src]=true;
        for(int destination : l[src]){
            if(!vis[destination]){
                dfsHelper(destination,vis);
            }
        }
    }
    void dfs(){
        int src=0;
        vector<bool>vis(V,false);
        dfsHelper(src,vis);
    }

};

int main()
{
    Graph g(5);
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(1, 3);
    g.addEdges(2, 4);
    // g.printGraph();
    g.bfs();
    cout <<endl;
    g.dfs();
    return 0;
}