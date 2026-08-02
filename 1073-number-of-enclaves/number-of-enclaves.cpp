class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& mat,vector<vector<int>>& vis){
           vis[row][col] = 1;

           int n = mat.size();
           int m = mat[0].size(); 
           int drow[] = {-1,0,+1,0};
           int dcol[] = {0,-1,0,+1};

           for(int i = 0;i<4;i++){
        
        int nr = row + drow[i];
        int nc = col + dcol[i];

         if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc] == 1 && !vis[nr][nc]){
            dfs(nr,nc,mat,vis);
         }
          

           }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
     int m = grid[0].size();
     vector<vector<int>> vis(n,vector<int>(m,0));

     
     for(int i = 0;i<m;i++){
        if(!vis[0][i] && grid[0][i] == 1){
            dfs(0,i,grid,vis);
        }
     }
        for(int i = 0;i<m;i++){
        if(!vis[n-1][i] && grid[n-1][i] == 1){
            dfs(n-1,i,grid,vis);
        }
        }
        for(int j = 0;j<n;j++){
        if(!vis[j][0] && grid[j][0] == 1){
            dfs(j,0,grid,vis);
        }
        }
        for(int j = 0;j<n;j++){
        if(!vis[j][m-1] && grid[j][m-1] == 1){
            dfs(j,m-1,grid,vis);
        }
        }


     
              int cnt = 0;
     for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == 1) cnt++;
        }
     }

     

      return cnt;  
    }
};