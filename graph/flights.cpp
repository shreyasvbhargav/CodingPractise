//https://leetcode.com/problems/cheapest-flights-within-k-stops/
//find min/cheapest flights for at max k stops given a flight vector : src, dest, price
/*
There are n cities connected by some number of flights.
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define ipair pair<int, int>

int minimum(int a, int b){
    return (a < b) ? a : b;
}

int findCheapestPrice(int n, vector<vector<int> > &flights, int src, int dst, int k){
    list<ipair> adj[n];
    queue<pair<int,int> > q;
    bool visited[n];
    uint min = INT_MAX;
    memset(visited, false, n);

    for(vector<vector<int> >::iterator it=flights.begin(); it!=flights.end(); it++ ){
        vector<int> fl = *it;
        int s = fl.at(0);
        int d = fl.at(1);
        int cost = fl.at(2);
        adj[s].push_back(make_pair(d, cost));
    }

    q.push(make_pair(src, 0));
    visited[src] = true;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            pair<int, int> node = q.front();
            //visited[node.first] = true;
            q.pop();
            
            if(k < -1 && min==INT_MAX){
                min = -1;
                break;
            }
            if(node.first == dst)
                min = minimum(min, node.second);
                //return node.second;

            
            for(auto it:adj[node.first]){
                if(!visited[it.first])
                    q.push(make_pair(it.first, node.second+it.second));
            }
        
        }
        k--;
    }
    return min;
}

int main(){
    int n = 4;
    vector<int> tmp;
    vector<vector<int> > flights;
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(100);
    flights.push_back(tmp);
    tmp.clear();

    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(100);
    flights.push_back(tmp);
    tmp.clear();

    tmp.push_back(2);
    tmp.push_back(0);
    tmp.push_back(100);
    flights.push_back(tmp);
    tmp.clear();

    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(600);
    flights.push_back(tmp);
    tmp.clear();

    tmp.push_back(2);
    tmp.push_back(3);
    tmp.push_back(200);
    flights.push_back(tmp);
    int src = 0, dest = 3, k=2;

    cout<<findCheapestPrice(n, flights, src, dest, k);
}