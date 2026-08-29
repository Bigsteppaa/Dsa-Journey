class Solution {

  int f(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp){

  if(ind1==0 || ind2==0) return 0;
  if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

  if(s1[ind1-1] == s2[ind2-1]) return dp[ind1][ind2] = 1 + f(ind1-1,ind2-1,s1,s2,dp);

  return dp[ind1][ind2] = max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));


  }



public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
     int n = text1.size();
     int m = text2.size();

        
           
        return f(text1.size(),text2.size(),text1,text2,dp);
        
    }
};