/*
    You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

    If isWater[i][j] == 0, cell (i, j) is a land cell.
    If isWater[i][j] == 1, cell (i, j) is a water cell.
    You must assign each cell a height in a way that follows these rules:

    The height of each cell must be non-negative.
    If the cell is a water cell, its height must be 0.
    Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another 
    cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
    Find an assignment of heights such that the maximum height in the matrix is maximized.

    Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are 
    multiple solutions, return any of them.
*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        queue<pair<int,int>>q;
        vector<vector<int>>dirs={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
                else ans[i][j]=-1;
            }
        }
        while(!q.empty()){
            pair<int,int> indexes = q.front();
            int r=indexes.first;
            int c=indexes.second;
            int h=ans[r][c];
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dirs[i][0];
                int newc=c+dirs[i][1];
                if(newr>=0 && newr<n && newc>=0 && newc<m && ans[newr][newc]==-1){
                    ans[newr][newc]=h+1;
                    q.push({newr,newc});
                }
            }
        }
        return ans;
    }
};