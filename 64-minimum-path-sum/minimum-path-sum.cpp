class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int  m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);


       dp[0] = grid[0][0];

       for(int i = 0;i<m;i++){
         vector<int> temp(n,0);
        for(int j = 0;j<n;j++){


        if(i == 0 && j == 0){
            temp[j] = dp[j];
            continue;
        }

        int left = grid[i][j];
        if(i>0) left += dp[j];
        else left += 1e9;

        int right = grid[i][j];
        if(j>0)right += temp[j-1];
        else right += 1e9;
              
                
       temp[j] = min(left,right);

        }
        dp = temp;
       }
  
        return dp[n-1];
        
    }
};