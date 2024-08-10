class Solution {
public:
    void dfs(int row,int col,int rows,int cols, int dr[],int dc[],vector<vector<int>>&matrix){
        matrix[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0&&ncol>=0&&nrow<rows&&ncol<cols&&matrix[nrow][ncol]==0){
                dfs(nrow,ncol,rows,cols,dr,dc,matrix);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int size=grid.size();

        vector<vector<int>>matrix(size*3,vector<int>(size*3,0));
        // int matrix[3*size][3*size]={0};
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                int row=i*3;
                int col=j*3;
                if(grid[i][j]=='/'){
                    matrix[row][col+2]=1;
                    matrix[row+1][col+1]=1;
                    matrix[row+2][col]=1;
                }
                else if(grid[i][j]=='\\'){
                    matrix[row][col]=1;
                    matrix[row+1][col+1]=1;
                    matrix[row+2][col+2]=1;
                }
            }

        }
        int cnt=0;
         int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<size*3;i++){
            for(int j=0;j<size*3;j++){
                if(matrix[i][j]==0){
                    dfs(i,j,size*3,size*3,dr,dc,matrix);
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};