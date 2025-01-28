/*
    You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

    A land cell if grid[r][c] = 0, or
    A water cell containing grid[r][c] fish, if grid[r][c] > 0.
    A fisher can start at any water cell (r, c) and can do the following operations any number of times:

    Catch all the fish at cell (r, c), or
    Move to any adjacent water cell.
    Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 
    if no water cell exists.

    An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) 
    if it exists.
*/

class Solution {
public:
    void f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int &cnt,vector<vector<int>>&dirs){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto idx = q.front();
            int r = idx.first;
            int c = idx.second;
            cnt+=grid[r][c];
            q.pop();
            for(int k=0;k<dirs.size();k++){
                int newrow = r+dirs[k][0];
                int newcol = c+dirs[k][1];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol] && !vis[newrow][newcol]){
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0,ans=0;
        vector<vector<int>>vis(n,vector<int>(m));
        vector<vector<int>>dirs={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    cnt=0;
                    f(i, j, grid, vis, cnt, dirs);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};