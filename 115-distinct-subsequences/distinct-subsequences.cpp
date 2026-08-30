class Solution {

int fu(int ind1,int ind2,string &s, string &f,vector<vector<int>> &dp){

 if(ind2 == 0) return 1;
 if(ind1 == 0) return 0;
 if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
 
 if(s[ind1-1] == f[ind2-1]) return dp[ind1][ind2] = fu(ind1-1,ind2-1,s,f,dp) + fu(ind1-1,ind2,s,f,dp);

return dp[ind1][ind2] = fu(ind1-1,ind2,s,f,dp);

}


public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fu(n,m,s,t,dp);
        
    }
};