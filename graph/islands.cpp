//Find the number of islands using DFS

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define ROW 5
#define COL 5
bool visited[ROW][COL];
int isvalid(int row, int col){
    return (row>=0 && row<ROW && col>=0 && col<COL);
}

int DFS(int row, int col, int M[][COL]){
    int dirx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int diry[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    visited[row][col] = true;

    for(int i=0; i<8; i++){
        if(isvalid(row + dirx[i], col + diry[i]) && M[row+dirx[i]][col+diry[i]] && !visited[row + dirx[i]][col + diry[i]]){
            DFS(row+dirx[i], col+diry[i], M);
            visited[row+dirx[i]][col+diry[i]] = true;
        }
    }
}

int countIslands(int M[][COL]){
    int islands = 0;
    //bool visited[ROW][COL];// = {false};
    memset(visited, false, ROW*COL);

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(M[i][j] && !visited[i][j]){
                DFS(i, j, M);
                islands++;
            }
        }
    }
    return islands;
}

int main(){

    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };
 
    printf("Number of islands is: %d\n", countIslands(M));
 
    return 0;
}