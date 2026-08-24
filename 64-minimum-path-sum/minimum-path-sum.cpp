class Solution {

 public: int f(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){

  if(r == 0 && c == 0) return grid[r][c];
  if(r<0 || c<0) return 1e9;
  if(dp[r][c] != -1) return dp[r][c];

  int left = grid[r][c] + f(r-1,c,grid,dp);
  int right = grid[r][c] + f(r,c-1,grid,dp);

   return dp[r][c] = min(left,right);

 }




public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int  m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
        
    }
};