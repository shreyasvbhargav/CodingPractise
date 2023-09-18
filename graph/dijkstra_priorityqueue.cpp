//explore Dijkstra algo implemented using minHeap : priority_queue<int, vector<int> greater_int<int> > 

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> iPair;

class Graph {
    int V; // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list<pair<int, int> >* adj;
 
public:
    Graph(int V); // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
 
    // prints shortest path from s
    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int weight){
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void Graph::shortestPath(int s){
    uint dist[V];
    int weight, adj_node;
    memset(dist, INT_MAX, V*sizeof(int));
    priority_queue< iPair, vector<iPair>, greater<iPair> > que;

    dist[s] = 0;
    que.push(make_pair(0, s));

    while(!que.empty()){
        int u = que.top().second;
        que.pop();

        for(auto it : adj[u]){
            adj_node = it.first;
            weight = it.second;

            if(dist[adj_node] > dist[u]+weight){
                dist[adj_node] = dist[u]+weight;
                que.push(make_pair(dist[adj_node], adj_node));
            }
        }
    }

    for(int i =0 ; i<V; i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}

int main(){
    int V = 9;
    Graph g(V);
 
    // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.shortestPath(0);
 
    return 0;
}