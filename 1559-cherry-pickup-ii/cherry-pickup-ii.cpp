class Solution {



public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(grid[0].size(),vector<int>(grid[0].size(),0));
   
   for(int i = 0;i<m;i++){
    for(int j = 0;j<m;j++){

  if(i == j) dp[i][j] = grid[n-1][j];
  else dp[i][j] =  grid[n-1][j] + grid[n-1][i];
 
    }
   }      
    
             
                  for(int i = n-2;i>=0;i--){
                     vector<vector<int>> temp(grid[0].size(),vector<int>(grid[0].size(),0));

                  for(int j1 = m-1;j1>=0;j1--){
                    for(int j2 = m-1;j2>=0;j2--){
         int maxi = 0;
      for(int a = -1;a<=1;a++){
        for(int b = -1;b<=1;b++){
            if(j1+a>= 0 && j1+a <m  && j2+b<m && j2+b>=0){
              if(j1 == j2) maxi = max(maxi,grid[i][j1] + dp[j1+a][j2+b]);
              else
                maxi = max(maxi,grid[i][j1] + grid[i][j2] +  dp[j1+a][j2+b]);
            }
                     

              
        }
    
       }  
       temp[j1][j2] = maxi;

                    }
                  }
                  dp = temp;
                  }


 return dp[0][m-1];
    }
};