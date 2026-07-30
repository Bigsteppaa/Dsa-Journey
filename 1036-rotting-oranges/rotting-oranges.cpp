class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       int vis[n][m];
       queue<pair<pair<int,int>,int>> q;
       int tot1 = 0;
       for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 2){
               q.push({{i,j},0});
               vis[i][j] = 2;

            }
            else vis[i][j] = 0;
            if(grid[i][j] ==1) tot1++;

        }
       }


       int drow[] = {-1,0,+1,0};
       int dcol[] = {0,-1,0,+1};
       int tim = 0;
       int fresh1 = 0;

       while(!q.empty()){

          int r = q.front().first.first;
           int c = q.front().first.second;
            int tm = q.front().second;
             q.pop();
             tim = max(tim,tm);
             for(int i = 0;i<4;i++){
                 int nr = r + drow[i];
                 int nc = c + dcol[i];
                 if(nr>= 0 && nr<n && nc>= 0 && nc<m && grid[nr][nc] == 1 && vis[nr][nc] != 2){
                    q.push({{nr,nc},tm+1});
                    vis[nr][nc] = 2;
                    fresh1++;

                 }

             }




       }
       
     return tot1 == fresh1?tim:-1;
        
    }
};