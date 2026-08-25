class Solution {

 public: int f(int i , int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
    if( j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()) return -1e9;
 if(i == grid.size()-1){
    if(j1 == j2) return grid[i][j1];
    else return grid[i][j1] + grid[i][j2];

 }  if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
 
          int maxi = 0;
       for(int a = -1;a<=1;a++){
        for(int b = -1;b<=1;b++){
              if(j1 == j2) maxi = max(maxi,grid[i][j1] + f(i+1,j1+a,j2+b,grid,dp));
              else{
                maxi = max(maxi,grid[i][j1] + grid[i][j2] +  f(i+1,j1+a,j2+b,grid,dp));


              }
        }
    
       }  
 



   return dp[i][j1][j2] = maxi;
 }




public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return f(0,0,grid[0].size()-1,grid,dp);

        
    }
};