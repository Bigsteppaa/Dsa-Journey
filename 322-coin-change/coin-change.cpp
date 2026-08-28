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
       vector<int> dp(amount+1,0);
        int n = coins.size();
        for(int j = 0;j<=amount;j++){
        if(j%coins[0] == 0){
            dp[j] = j/coins[0];
        }
        else dp[j] = 1e9;
        }

        for(int i = 1;i<n;i++){
            vector<int> curr(amount+1,0);
        for(int j = 1;j<=amount;j++){

         int r = INT_MAX;
      if(coins[i]<=j) r = 1 + curr[j-coins[i]];
      int l =  dp[j];
       

        curr[j] = min(l,r);


        }
 dp = curr;
        }
        
       
   int ans = dp[amount];
   if(ans>amount) return -1;
        return ans;
        
    }
};