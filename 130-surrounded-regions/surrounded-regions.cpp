class Solution {
    private:
    void dfs(int row,int col,vector<vector<char>>& mat,vector<vector<int>>& vis){
           vis[row][col] = 1;

           int n = mat.size();
           int m = mat[0].size(); 
           int drow[] = {-1,0,+1,0};
           int dcol[] = {0,-1,0,+1};

           for(int i = 0;i<4;i++){
        
        int nr = row + drow[i];
        int nc = col + dcol[i];

         if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc] == 'O' && !vis[nr][nc]){
            dfs(nr,nc,mat,vis);
         }
          

           }
    }
public:
    void solve(vector<vector<char>>& board) {

     int n = board.size();
     int m = board[0].size();
     vector<vector<int>> vis(n,vector<int>(m,0));

     
     for(int i = 0;i<m;i++){
        if(!vis[0][i] && board[0][i] == 'O'){
            dfs(0,i,board,vis);
        }
     }
        for(int i = 0;i<m;i++){
        if(!vis[n-1][i] && board[n-1][i] == 'O'){
            dfs(n-1,i,board,vis);
        }
        }
        for(int j = 0;j<n;j++){
        if(!vis[j][0] && board[j][0] == 'O'){
            dfs(j,0,board,vis);
        }
        }
        for(int j = 0;j<n;j++){
        if(!vis[j][m-1] && board[j][m-1] == 'O'){
            dfs(j,m-1,board,vis);
        }
        }


     

     for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
        }
     }

     


    }
};