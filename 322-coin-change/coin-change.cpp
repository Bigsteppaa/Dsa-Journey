class Solution {


int f(int n,int amount,vector<int>& coins,vector<vector<int>>& dp){

if(amount == 0) return 0;
if(n == 0 ){
    
    if(amount%coins[0] == 0) return amount/coins[0] ;
      return 1e9;
      
}
if(dp[n][amount] != -1) return dp[n][amount];
int r = INT_MAX;
      if(coins[n]<=amount) r = 1 + f(n,amount-coins[n],coins,dp);
      int l =  f(n-1,amount,coins,dp);
       

      return dp[n][amount] = min(l,r);
}


public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        int n = coins.size();
        for(int j = 0;j<=amount;j++){
        if(j%coins[0] == 0){
            dp[0][j] = j/coins[0];
        }
        else dp[0][j] = 1e9;
        }

        for(int i = 1;i<n;i++){
        for(int j = 1;j<=amount;j++){

         int r = INT_MAX;
      if(coins[i]<=j) r = 1 + dp[i][j-coins[i]];
      int l =  dp[i-1][j];
       

      dp[i][j] = min(l,r);


        }

        }
        
       
   int ans = dp[n-1][amount];
   if(ans>amount) return -1;
        return ans;
        
    }
};