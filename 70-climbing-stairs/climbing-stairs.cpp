class Solution {
     int dpsol(int n,vector<int> &dp) {
        if(n == 0) return 1;
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];


    return dp[n] = dpsol(n-1,dp) + dpsol(n-2,dp);

    }
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n<0) return 0;
        vector<int> dp(n+1,-1);


    return dpsol(n,dp);

    }
};