class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n = grid.size();
        
           
     vector<vector<int>> dist(n,vector<int>(n,1e9));

      queue<pair<int,int>> q;

      q.push({0,0});
      dist[0][0] = 1;

      while(!q.empty()){
        auto[row,col] = q.front();
           q.pop();
         for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){
               int nr = row + i;
               int nc = col + j;
             if( nr>=0 && nr<n && nc>=0 && nc<n && !grid[nr][nc]
             && dist[row][col]+1<dist[nr][nc]){
                dist[nr][nc] = dist[row][col]+1;
                q.push({nr,nc});
             }


            }
         }
    


      }


     if(dist[n-1][n-1] == 1e9) return -1;


     return dist[n-1][n-1];
    }
};