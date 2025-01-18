/*
    Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if 
    you are currently in this cell. The sign of grid[i][j] can be:

    1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
    2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
    3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
    4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
    Notice that there could be some signs on the cells of the grid that point outside the grid.

    You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts 
    from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs 
    on the grid. The valid path does not have to be the shortest.

    You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

    Return the minimum cost to make the grid have at least one valid path.
*/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(),cols=grid[0].size();
        vector<vector<int>>dirs = { {0,1},{0,-1},{1,0},{-1,0}} ;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0,0,0});
        vector<vector<int>>mincost(rows,vector<int>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mincost[i][j]=INT_MAX;
            }
        }
        mincost[0][0]=0;
        while(!pq.empty()){
            auto curr = pq.top();
            int cost = curr[0];
            int row = curr[1];
            int col = curr[2];
            pq.pop();
            if(mincost[row][col]<cost) continue;
            for(int dir=0;dir<4;dir++){
                int nextrow = row+dirs[dir][0];
                int nextcol = col+dirs[dir][1];
            
            if(nextrow>=0 && nextrow<rows && nextcol>=0 && nextcol<cols){
                int nextcellcost = (dir+1) == grid[row][col] ? 0 :1;
                int newcost = cost + nextcellcost;
                if(newcost<mincost[nextrow][nextcol]){
                    mincost[nextrow][nextcol] = newcost;
                    pq.push({newcost,nextrow,nextcol});
                }
            }
            }

        }return mincost[rows-1][cols-1];
    }
};