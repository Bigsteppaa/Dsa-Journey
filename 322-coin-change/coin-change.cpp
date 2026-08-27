class Solution {


int f(int n,int amount,vector<int>& arr,vector<vector<int>>& dp){

if(amount == 0) return 0;
if(n == 0 ){
    
    if(amount%arr[0] == 0) return amount/arr[0] ;
      return 1e9;
      
}
if(dp[n][amount] != -1) return dp[n][amount];
int r = INT_MAX;
      if(arr[n]<=amount) r = 1 + f(n,amount-arr[n],arr,dp);
      int l =  f(n-1,amount,arr,dp);
       

      return dp[n][amount] = min(l,r);
}


public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
       
   int ans = f(coins.size()-1,amount,coins,dp);
   if(ans>amount) return -1;
        return ans;
        
    }
};