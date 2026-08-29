class Solution {




public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
     int n = text1.size();
     int m = text2.size();


     for(int ind1 = 1;ind1<=n;ind1++){
        for(int ind2 = 1;ind2<=m;ind2++){

if(text1[ind1-1] == text2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
   else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);

        }
     }

    

        
           
        return dp[n][m];
        
    }
};