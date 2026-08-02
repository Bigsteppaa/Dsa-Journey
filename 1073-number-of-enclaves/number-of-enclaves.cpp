class Solution {
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
     int m = grid[0].size();
     vector<vector<int>> vis(n,vector<int>(m,0));
     queue<pair<int,int>> q;

     
     for(int i = 0;i<m;i++){
        if(!vis[0][i] && grid[0][i] == 1){
            vis[0][i] = 1;
            q.push({0,i});
        }
     }
        for(int i = 0;i<m;i++){
        if(!vis[n-1][i] && grid[n-1][i] == 1){
            vis[n-1][i] = 1;
            q.push({n-1,i});
        }
        }
        for(int j = 0;j<n;j++){
        if(!vis[j][0] && grid[j][0] == 1){
            vis[j][0] = 1;
            q.push({j,0});
        }
        }
        for(int j = 0;j<n;j++){
        if(!vis[j][m-1] && grid[j][m-1] == 1){
            vis[j][m-1] = 1;
            q.push({j,m-1});
        }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            

            int drow[] = {-1,0,+1,0};
           int dcol[] = {0,-1,0,+1};
           for(int i = 0;i<4;i++){
        
        int nr = r + drow[i];
        int nc = c + dcol[i];

         if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 && !vis[nr][nc]){
            vis[nr][nc] = 1;
                q.push({nr,nc});
         }
          

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