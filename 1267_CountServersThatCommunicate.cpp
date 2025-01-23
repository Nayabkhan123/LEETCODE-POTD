/*
    You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that 
    on that cell there is a server and 0 means that it is no server. Two servers are said to communicate 
    if they are on the same row or on the same column.

    Return the number of servers that communicate with any other server.
*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>row(n);
        vector<int>col(m);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                    cnt++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==1 && row[i] == 1 && col[j] == 1){
                    cnt--;
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),cnt=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        while(!q.empty()){
            pair<int,int> indexes = q.front();
            int row = indexes.first;
            int col = indexes.second;
            q.pop();
            for(int i=0;i<n;i++){
                int newr=i;
                int newc=col;
                if(row==newr) continue;
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                    grid[newr][newc]=-1;
                    cnt+=1;
                }
            }
            for(int i=0;i<m;i++){
                int newr=row;
                int newc=i;
                if(col==newc) continue;
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                    grid[newr][newc]=-1;
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};