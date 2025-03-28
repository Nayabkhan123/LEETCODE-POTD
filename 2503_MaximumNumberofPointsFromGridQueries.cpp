/*
    You are given an m x n integer matrix grid and an array queries of size k.

    Find an array answer of size k such that for each integer queries[i] you start 
    in the top left cell of the matrix and repeat the following process:

    If queries[i] is strictly greater than the value of the current cell that you are in, 
    then you get one point if it is your first time visiting this cell, and you can move 
    to any adjacent cell in all 4 directions: up, down, left, and right.
    Otherwise, you do not get any points, and you end this process.
    After the process, answer[i] is the maximum number of points you can get. Note that 
    for each query you are allowed to visit the same cell multiple times.

    Return the resulting array answer.
*/

class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            set<int>queriesSet(queries.begin(),queries.end());
            int cnt=0,n=grid.size(),m=grid[0].size();
            unordered_map<int,int>queryCount;
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
            pq.push({grid[0][0],{0,0}});
            vector<vector<bool>>vis(n,vector<bool>(m,false));
            vis[0][0]=true;
            vector<vector<int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
            for(auto it : queriesSet){
                while(!pq.empty()){
                    auto top = pq.top();
                    int currRow = top.second.first;
                    int currCol = top.second.second;
                    pq.pop();
                    vis[currRow][currCol]=true;
                    if(top.first<it){
                        cnt++;
                        for(int i=0;i<4;i++){
                            int row = currRow + dir[i][0];
                            int col = currCol + dir[i][1];
                            if(row>=0 && col>=0 && row<n && col<m && !vis[row][col]){
                                vis[row][col]=true;
                                pq.push({grid[row][col],{row,col}});
                            }
                        }
                    }
                    else{
                        pq.push(top);
                        break;
                    }
                    
                }
                queryCount[it]=cnt;
            }
            vector<int>ans;
            for(auto it : queries){
                ans.push_back(queryCount[it]);
            }
            return ans;
        }
    };