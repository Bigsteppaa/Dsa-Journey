class Solution {


    bool f(int i,int j,string &s, string &p,vector<vector<int>> &dp){

        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
            for(int i = 0;i<=j;i++){
                if(p[i] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];



    if(s[i] == p[j] || p[j] == '?') return dp[i][j] = f(i-1,j-1,s,p,dp);
     
if(p[j] == '*'){
    return dp[i][j] = f(i,j-1,s,p,dp) || f(i-1,j,s,p,dp);
}


return dp[i][j] = false;


    }
public:
    bool isMatch(string s, string p) {
       
        int n = s.size();
        int m = p.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
        
    }
};