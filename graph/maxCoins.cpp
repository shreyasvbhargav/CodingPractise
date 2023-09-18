// https://www.geeksforgeeks.org/maximum-coin-in-minimum-time-by-skipping-k-obstacles-along-path-in-matrix/
//given a 2d matrix of coins and obstacles, task is to collect max coins from (i1, j1) to (i2, j2) with atmost k obstacles

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define ROWS 4
#define COLS 4

typedef struct cell{
    int x;
    int y;
    int k;
    int coins;
    cell(int a, int b, int c, int d):x(a),y(b),k(c),coins(d){}
    cell(){}
}cell;

bool isValid(vector<vector<char> > grid, int x, int y){
   // int cols = grid[0].size();
   // int rows = grid.size()/cols;

    return (x>=0 && x<ROWS && y>=0 && y<COLS);
}

int collectMaxCoins(vector<vector<char> > grid, int i1, int j1, int i2, int j2, int k){
    int x, y;
    int dirx[] = {-1, 0, 1, 0};
    int diry[] = {0, 1, 0, -1};
    queue<cell> q;
    int size;
    cell *tmp = (cell *)malloc(sizeof(cell));
    int coins[ROWS][COLS];
    memset(coins, 0, ROWS*COLS);
    bool visited[k][ROWS][COLS];
    memset(visited, false, k*ROWS*COLS);

    cell c;
    c.x=i1; c.y=j1; c.k = k; c.coins=(grid[i1][j1]-'0');
    coins[i1][j1] = grid[i1][j1];
    visited[k][i1][j1] = true;
    q.push(c);

    while(!q.empty()){
        *tmp = q.front();
        size = q.size();
        q.pop();

        if(tmp->x == i2 && tmp->y == j2)
            return tmp->coins;

        while(size--){
            for(int i=0; i<4; i++){
                //up
                x = tmp->x+dirx[i];
                y = tmp->y+diry[i];
                if(isValid(grid, x,y)){
                    if(grid[x][y] == '*' && tmp->k && !visited[(tmp->k)-1][x][y]){
                        q.push(cell(x, y, (tmp->k)-1, tmp->coins));
                        visited[(tmp->k)-1][x][y] = true;
                    }
                    else if(grid[x][y]!='*' && !visited[tmp->k][x][y]){
                        q.push(cell(x, y, tmp->k, tmp->coins+grid[x][y]));
                        visited[tmp->k][x][y] = true;
                        coins[x][y] = max(coins[x][y], tmp->coins+grid[x][y]-'0');
                    }
                }
            }
        }
    }
    return coins[ROWS-1][COLS-1];
}

int main(){
    vector<vector<char> > grid;/* = { { '*', '0', '1', '2' },
                                   { '0', '0', '*', '*' },
                                   { '*', '*', '6', '8' },
                                   { '0', '0', '0', '1' } };*/
    vector<char> arr;
    arr.push_back('*');
    arr.push_back('0');
    arr.push_back('1');
    arr.push_back('2');
    grid.push_back(arr);

    arr.push_back('0');
    arr.push_back('0');
    arr.push_back('*');
    arr.push_back('*');
    grid.push_back(arr);

    arr.push_back('*');
    arr.push_back('*');
    arr.push_back('6');
    arr.push_back('8');
    grid.push_back(arr);

    arr.push_back('0');
    arr.push_back('0');
    arr.push_back('0');
    arr.push_back('1');
    grid.push_back(arr);

    int i1 = 0, j1 = 2;
    int i2 = 3, j2 = 3;
    int K = 1;

    cout<<collectMaxCoins(grid, i1, j1, i2, j2, K);
}