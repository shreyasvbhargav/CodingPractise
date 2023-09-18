//given undirected graph & value x, find level of node x. if x not found, return -1

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int vertices;
    vector<list<int> > edges;
    vector<int> visited;
    vector<int> level;
    public:
        Graph(int v){
            this->vertices = v;
            this->edges.resize(vertices);
            visited.resize(vertices, 0);
            level.resize(vertices, 0);
        }

        void createGraph();
        void BFS(int node);
        int findLevel(int X, int);
};

void Graph::createGraph(){
    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[1].push_back(0);
    edges[1].push_back(3);
    edges[2].push_back(0);
    edges[2].push_back(4);
    edges[3].push_back(1);
    edges[3].push_back(5);
    edges[4].push_back(2);
    edges[5].push_back(3);
}

int Graph::findLevel(int X, int root){
    queue<int> q;
    int lev = 0;
    int tmp;

    q.push(root);
    level[root] = lev;

    while(!q.empty()){
        tmp = q.front();
        q.pop();
        
        for(auto it : edges[tmp]){
            if(!visited[it]){
                q.push(it);
                visited[tmp] = 1;
                level[it] = level[tmp]+1;
                if(it == X)
                    return level[it];
            }
        }
    }
    return -1;
}

int main(){
    int nodes = 6;
    int X = 10;
    Graph g(nodes);
    g.createGraph();

    cout<<g.findLevel(X, 0)<<endl;
}