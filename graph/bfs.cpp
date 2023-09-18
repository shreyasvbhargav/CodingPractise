#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int vertices;
    vector<list<int> > edges;
    vector<int> visited;
    public:
        Graph(int v){
            this->vertices = v;
            this->edges.resize(vertices);
            visited.resize(vertices, 0);
        }

        void createGraph();
        void BFS(int node);
};

void Graph::createGraph(){
    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[1].push_back(2);
    edges[2].push_back(0);
    edges[2].push_back(3);
    edges[3].push_back(3);
}

void Graph::BFS(int node){
    queue<int> q;
    int tmp;

    q.push(node);

    while(!q.empty()){
        tmp = q.front();
        visited[tmp] = 1;
        q.pop();

        cout<<tmp<<endl;
        for(auto it : edges[tmp]){
            if(!visited[it]){
            //cout<<"Pushing : "<<it<<endl;
            q.push(it);
            visited[it] = 1;
            }
        }
    }
}

int main(){
    int nodes = 4;
    Graph obj(nodes);
    obj.createGraph();
    obj.BFS(2);
}