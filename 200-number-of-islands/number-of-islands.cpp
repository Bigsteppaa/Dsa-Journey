class Solution {

private:
void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis){
       vis[r][c] = 1;

    int drow[] = {-1,0,+1,0};
    int dcol[] = {0,-1,0,+1};
    int n = vis.size();
    int m = vis[0].size();

    for(int i = 0;i<4;i++){

     int nr = r + drow[i];
     int nc = c + dcol[i];

     if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == '1' && !vis[nr][nc]){
        dfs(nr,nc,grid,vis);
     }


    }



  }

public:
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j] ){
                    dfs(i,j,grid,vis);
                      cnt++;


                }
              

               


            }
        }

      return cnt; 
        
    }
};