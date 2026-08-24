class Solution {
     public: int sol(int r,int c,vector<vector<int>> &dp,vector<vector<int>>& mat){
  if(r == 0 && c == 0) return 1;
  if(r<0 || c<0 ) return 0;
  if(mat[r][c]) return 0;
  if(dp[r][c] != -1) return dp[r][c];

    return dp[r][c] = sol(r-1,c,dp,mat) + sol(r,c-1,dp,mat);
 }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0; 
         vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));


    return sol(obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp,obstacleGrid);
    
        
    }
};