/* 
Breadth-first search (BFS) is an algorithm for searching a tree data structure for a node that satisfies a given property. 
It starts at the tree root and explores all nodes at the present depth prior to moving on to the nodes at the next depth level.

Depth-first search explores the node branch as far as possible before backtracking and expanding other nodes.

Here, we will perform BFS and DFS on a 2D matrix. The approach is similar to its definition where we will explore all the elements of the 
matrix using either of the two methods.
*/


// We are taking row=3 , column=3

#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

bool valid(int i,int j,vector<vector<bool>>& vis){
    if(i<0 || j<0 || i>=3 || j>=3 || vis[i][j]==true)
        return false;
    return true;
}

void bfs(vector<vector<int>> mat,vector<vector<bool>>& vis){
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=true;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        cout<<mat[x][y]<<"\t";
        for(int i=0;i<4;i++){
            int x_dx=x+dx[i];
            int y_dy=y+dy[i];
            if(valid(x_dx,y_dy,vis))
            {
                vis[x_dx][y_dy]=true;
                q.push({x_dx,y_dy});
            }
        }
    }
}

void dfs(vector<vector<int>> mat,vector<vector<bool>>& vis){
    stack<pair<int,int>> stk;
    stk.push({0,0});
    vis[0][0]=true;
    while(!stk.empty()){
        int x=stk.top().first;
        int y=stk.top().second;
        stk.pop();
        cout<<mat[x][y]<<"\t";
        for(int i=0;i<4;i++){
            int x_dx=x+dx[i];
            int y_dy=y+dy[i];
            if(valid(x_dx,y_dy,vis))
            {
                vis[x_dx][y_dy]=true;
                stk.push({x_dx,y_dy});
            }
        }
    }
}

int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<bool>> vis(3,vector<bool>(3,false));   //visited matrix
    cout<<"\nBFS: \n";
    bfs(mat,vis);
    vector<vector<bool>> vis2(3,vector<bool>(3,false));
    cout<<"\nDFS: \n";
    dfs(mat,vis2);
    return 0;
}