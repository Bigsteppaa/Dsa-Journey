class Solution {
 
 int f(int n,int tar,vector<int>& coins,vector<vector<int>> &dp){

 
if(n == 0){
  if(tar%coins[0] == 0) return 1;
     return 0;
} 
if(dp[n][tar] != -1) return dp[n][tar]; 

     int pick = 0;
     if(coins[n]<=tar) pick = f(n,tar-coins[n],coins,dp);
      int not_pick = f(n-1,tar,coins,dp);

    return dp[n][tar] = pick + not_pick;

 }



public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
        
    }
};