// Dijkstra shortest path algorithm for Adjacency Matrix
//Adjacency list contains vector of list : vector<list<int> > adj where adj[index] will given a list of vertices adjacent of node 'index'


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define V 9

int findMin(uint dist[], bool visited[]){
    int min = INT_MAX, min_node=0;
    for(int i=0; i<V; i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i];
            min_node = i;
        }
    }
    return min_node;
}

void print(uint dist[V]){
    for(int i=0; i<V; i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}

void dijkstra(int graph[V][V], int source){
    uint dist[V];
    bool visited[V];

    memset(dist, INT_MAX, V*sizeof(int));
    memset(visited, false, V*sizeof(bool));

    dist[source] = 0;

    for(int i=0; i<V; i++){
        int node = findMin(dist, visited);

        visited[node] = true;

        for(int v=0; v<V; v++){
            if( graph[node][v] && ( dist[v] > (dist[node]+graph[node][v]) ) ){
                dist[v] = dist[node]+graph[node][v];
            }
        }
    }
    print(dist);
}


int main()
{
 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    // Function call
    dijkstra(graph, 0);
 
    return 0;
}